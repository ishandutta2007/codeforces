#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 500009;
int a[MAX_N];
int n, c;
vector<int> v[MAX_N];
int cnt[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    cnt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1];
        if (a[i] == c)
            cnt[i]++;
    }
    int ans = 0;
    for (int i = 0; i < MAX_N; i++)
    {
        if (v[i].empty() || i == c)
            continue;
        int mi = 0;
        for (int e = 0; e < (int)v[i].size(); e++)
        {
            int cur = e + 1 - cnt[v[i][e]];
            mi = min(mi, e - cnt[v[i][e]]);
            ans = max(ans, cur - mi);
        }
    }
    cout << ans + cnt[n];
}