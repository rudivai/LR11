#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Якщо треба, можна ініціалізувати додатково
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_calc_clicked()
{
    double A = ui->doubleSpinBox_A->value();
    double B = ui->doubleSpinBox_B->value();

    if (A == 0) {
        QMessageBox::warning(this, "Помилка", "Коефіцієнт A не може бути 0!");
        ui->label_result->setText("Помилка");
        return;
    }

    double x = -B / A;
    ui->label_result->setText(QString("x = %1").arg(x, 0, 'f', 2));

    addToHistory(A, B, x);
}

void MainWindow::addToHistory(double A, double B, double x)
{
    QString entry = QString("A=%1, B=%2 → x=%3").arg(A).arg(B).arg(x, 0, 'f', 2);
    ui->listWidget_history->addItem(entry);
}
