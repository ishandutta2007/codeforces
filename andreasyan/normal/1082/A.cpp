#include <bits/stdc++.h>
using namespace std;

int n, x, y, d;

void solv()
{
    cin >> n >> x >> y >> d;
    int ans = n + n;
    if (abs(x - y) % d == 0)
        ans = abs(x - y) / d;
    if (abs(1 - y) % d == 0)
        ans = min(ans, abs(x - 1) / d + 1 + abs(1 - y) / d);
    if (abs(n - y) % d == 0)
        ans = min(ans, abs(n - x) / d + 1 + abs(n - y) / d);
    if (ans == n + n)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}