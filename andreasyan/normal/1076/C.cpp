#include <bits/stdc++.h>
using namespace std;
const long double EPS = 0.000000000001;

void solv()
{
    long double d;
    cin >> d;
    long double l = 0, r = d / 2;
    while ((r - l) > EPS)
    {
        long double m = (l + r) / 2;
        if (m * (d - m) < d)
            l = m;
        else
            r = m;
    }
    long double t = l * (d - l) - (l + d - l);
    if (t < 0)
        t *= -1;
    if ((t < EPS * 10000))
        cout << "Y " << l << ' ' << (d - l) << endl;
    else
        cout << 'N' << endl;
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}