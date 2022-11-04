#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

struct node {
    double a, b;
    node() {}
    node(double _1, double _2) {a = _1, b = _2;}
};

double Abs(double x) {return x < 0 ? -x : x;}

double sqr(double x) {return x * x;}

double dise(node A, node B) {return sqrt(sqr(A.a - B.a) + sqr(A.b - B.b));}

double dism(node A, node B) {return Abs(A.a - B.a) + Abs(A.b - B.b);}

double D[11][11];

node X[11];

int main() {
    double a, b, c, X1, Y1, X2, Y2;
    scanf("%lf%lf%lf%lf%lf%lf%lf", &a, &b, &c, &X1, &Y1, &X2, &Y2);
    if(a == 0 || b == 0) return printf("%.12lf\n", dism(node(X1, Y1), node(X2, Y2))), 0;
    X[1] = node(X1, Y1);
    X[2] = node(X2, Y2);
    X[3] = node(X1, -(c + a * X1) / b);
    X[4] = node(X2, -(c + a * X2) / b);
    X[5] = node(-(c + b * Y1) / a, Y1);
    X[6] = node(-(c + b * Y2) / a, Y2);
    for(int i = 1; i <= 6; i++)
        for(int j = 1; j <= 6; j++)
            D[i][j] = 1e100;
    for(int i = 1; i <= 2; i++)
        for(int j = i + 1; j <= 6; j++)
            D[i][j] = (D[j][i] = dism(X[i], X[j]));
    for(int i = 3; i <= 6; i++)
        for(int j = i + 1; j <= 6; j++)
            D[i][j] = (D[j][i] = dise(X[i], X[j]));
    for(int i = 1; i <= 6; i++)
        for(int j = 1; j <= 6; j++)
            for(int k = 1; k <= 6; k++)
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
    printf("%.12lf\n", D[1][2]);
    return 0;
}