#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int t[n + 1];
    int d[n + 1];
    t[0] = -3000;
    d[0] = 0;
    int tm[] = {90, 1440};
    int cs[] = {50, 120};
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
        d[i] = d[i - 1] + 20;
        for(int j = 0; j < 2; j++)
        {
            auto it = lower_bound(t, t + i, t[i] - tm[j] + 1) - t;
            d[i] = min(d[i], d[it - 1] + cs[j]);
        }
        cout << d[i] - d[i - 1] << endl;
    }
    return 0;
}