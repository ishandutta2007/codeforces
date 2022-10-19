#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    double l, p, q;
    cin >> l >> p >> q;
    double t = l / (p + q);
    cout << p * t << endl;
    return 0;
}