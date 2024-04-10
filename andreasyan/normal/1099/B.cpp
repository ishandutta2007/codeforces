#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int32_t main()
{
    cin >> n;
    int t = sqrt(n);
    int ans = n + 2;
    for (int i = max(1LL, t - 10); i <= min(n, t + 10); ++i)
    {
        int l = 1, r = n;
        while ((r - l) > 4)
        {
            int m = (l + r) / 2;
            if (i * m >= n)
                r = m;
            else
                l = m;
        }
        for (int m = l; m <= r; ++m)
        {
            if (i * m >= n)
            {
                ans = min(ans, i + m);
            }
        }
    }
    cout << ans << endl;
    return 0;
}