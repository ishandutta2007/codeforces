#include <bits/stdc++.h>
using namespace std;
const long double pi = 4 * atan(1.0);

int main()
{
    long double n, r;
    cin >> n >> r;
    long double a = pi / n;
    long double b = 2 * a;
    cout.precision(7);
    cout<<fixed<<r * r * sin(a / 2) * sin(a) / sin(a + a/2) * n;
    return 0;
}