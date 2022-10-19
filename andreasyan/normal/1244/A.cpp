#include <bits/stdc++.h>
using namespace std;

void solv()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = a / c;
    if (a % c)
        ++x;
    int y = b / d;
    if (b % d)
        ++y;
    if (x + y <= k)
        cout << x << ' ' << y << endl;
    else
        cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}