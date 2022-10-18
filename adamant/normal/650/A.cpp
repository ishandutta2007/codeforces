#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    map<int, int> Y;
    map<int, map<int, int>> XY;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        Y[y[i]]++;
        XY[x[i]][y[i]]++;
    }
    int ans = 0;
    for(auto it: XY)
    {
        int sum = 0;
        for(auto jt: it.second)
        {
            ans -= jt.second * (jt.second - 1) / 2;
            sum += jt.second;
        }
        ans += 1LL * sum * (sum - 1) / 2;
    }
    for(auto it: Y)
    {
        ans += it.second * (it.second - 1) / 2;
    }
    cout << ans << "\n";
}