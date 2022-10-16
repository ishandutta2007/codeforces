#include <iostream>
#include <cmath>

#define double long double
using namespace std;

double get2(double x, double y, double z) {
    //(x ^ y) ^ z
    return y * z * log(x);
}

const double eps = 1e-10;

bool bigger(double a, double b) {
    //a > b
    return a - b > 0; //-eps;
}

bool equal(double a, double b) {
    return abs(a - b) < eps;
}

double best;
int best_pos;
int pos;

void try1(double x, double y, double z, bool sure = false) {
    ++ pos;

    //x ^ y ^ z
    double val = pow(y, z) * log(x);

    if (bigger(val, best) || sure) {
        best = val;
        best_pos = pos;
    }
}

void try2(double x, double y, double z, bool sure = false) {
    ++ pos;

    //(x ^ y) ^ z
    double val = y * z * log(x);

    if (bigger(val, best) || sure) {
        best = val;
        best_pos = pos;
    }
}


int main()
{
    double x, y, z;
    cin >> x >> y >> z;

    try1(x, y, z, true);
    try1(x, z, y);
    try2(x, y, z);
    try2(x, z, y);

    try1(y, x, z);
    try1(y, z, x);
    try2(y, x, z);
    try2(y, z, x);

    try1(z, x, y);
    try1(z, y, x);
    try2(z, x, y);
    try2(z, y, x);

    if (best_pos == 1)
        cout << "x^y^z\n";
    else if (best_pos == 2)
        cout << "x^z^y\n";
    else if (best_pos == 3)
        cout << "(x^y)^z\n";
    else if (best_pos == 4)
        cout << "(x^z)^y\n";
    else if (best_pos == 5)
        cout << "y^x^z\n";
    else if (best_pos == 6)
        cout << "y^z^x\n";
    else if (best_pos == 7)
        cout << "(y^x)^z\n";
    else if (best_pos == 8)
        cout << "(y^z)^x\n";
    else if (best_pos == 9)
        cout << "z^x^y\n";
    else if (best_pos == 10)
        cout << "z^y^x\n";
    else if (best_pos == 11)
        cout << "(z^x)^y\n";
    else if (best_pos == 12)
        cout << "(z^y)^x\n";

    return 0;
}