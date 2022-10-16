#include <bits/stdc++.h>

#define double long double
using namespace std;

double cott = 1.37638192047117353820720958l * 5 / 4;

int main()
{
    double volumul = 8.140576474687l;
    double aria = 15.484296605301l;

    double h = volumul / aria;

    double l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    double v1 = l1 * l1 * l1 / (6 * sqrt(2));
    double v2 = l2 * l2 * l2 / (3 * sqrt(2));

    double v3 = cott * l3 * l3 * l3 * h / 3;

    double ans = v1 + v2 + v3;

    cout << fixed << setprecision(12) <<  ans << '\n';
    return 0;
}