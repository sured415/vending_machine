#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_money(bool flage, int a)
{
    if(flage) this->money_ += a;
    else this->money_ -= a;
    ui->lcdNumber->display(this->money_);
    set_pb();
}

void Widget::set_pb()
{
    if(this->money_ >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if(this->money_ >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if(this->money_ >= 200) ui->pbCola->setEnabled(true);
    else ui->pbCola->setEnabled(false);
    if(this->money_ > 0) ui->pbReturn->setEnabled(true);
    else ui->pbReturn->setEnabled(false);
}

void Widget::on_pb500_clicked()
{
    set_money(1, 500);
}

void Widget::on_pb100_clicked()
{
    set_money(1, 100);
}

void Widget::on_pb50_clicked()
{
    set_money(1, 50);
}

void Widget::on_pb10_clicked()
{
    set_money(1, 10);
}

void Widget::on_pbCoffee_clicked()
{
    set_money(0, 100);
}

void Widget::on_pbTea_clicked()
{
    set_money(0, 150);
}

void Widget::on_pbCola_clicked()
{
    set_money(0, 200);
}

void Widget::on_pbReturn_clicked()
{
    QString message;
    int total, count;
    total = this->money_;

    message = "Return Total = " + QString::number(total) + ", 500 * ";
    count = total / 500;
    message += QString::number(count);
    message += ", 100 * ";
    total -= 500 * count;
    count = total / 100;
    message += QString::number(count);
    message += ", 50 * ";
    total -= 100 * count;
    count = total / 500;
    message += QString::number(count);
    message += ", 10 * ";
    total -= 50 * count;
    count = total / 10;
    message += QString::number(count);

    set_money(0, this->money_);
    QMessageBox::information(this, "Return", message, "OK");
}
