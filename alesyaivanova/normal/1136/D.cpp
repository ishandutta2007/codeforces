#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MN = 300009;
int p[MN];
vector<int> g[MN];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p[x] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = p[a];
        b = p[b];
        g[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
        sort(g[i].rbegin(), g[i].rend());
    vector<int> v;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0;
        for (int e : g[i])
        {
            if (j < (int)v.size() && e == v[j])
                j++;
        }
        if (j == (int)v.size() && i < n - 1)
            ans++;
        else
            v.push_back(i);
    }
    cout << ans;
}