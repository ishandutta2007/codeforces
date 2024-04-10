#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

const int inf = 2e12 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    int c[n], v[n];
    for(int i = 0; i < n; i++)
        cin >> c[i] >> v[i];
    int g[k + 2];
    for(int i = 1; i <= k; i++)
        cin >> g[i];
    g[0] = 0, g[k + 1] = s;
    sort(g, g + k + 2);
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b){return v[a] < v[b];});
    int l = -1, r = n;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        int V = v[p[m]];
        int T = 0;
        for(int i = 1; i <= k + 1; i++)
        {
            int dist = g[i] - g[i - 1];
            //k1 + k2 = dist
            //2 * k2 + k1 <= V
            //0 <= k2 <= V - dist
            //k1 >= 2 * dist - V
            //k2 >= 0, k1 >= 0
            int k2 = V - dist;
            int k1 = dist - k2;
            //cout << k1 << ' ' << k2 << endl;
            if(k2 < 0)
                T = inf;
            if(k1 < 0)
            {
                k1 = 0, k2 = dist;
            }
            //cout << dist << ' ' << k1 << ' ' << k2 << endl;
            assert(T >= inf || k1 + k2 == dist && 2 * k2 + k1 <= V && k1 >= 0 && k2 >= 0);
            T += 2 * k1 + k2;
        }
        if(T <= t)
            r = m;
        else
            l = m;
    }
    if(r == n)
    {
        cout << -1 << endl;
        return 0;
    }
    //cout << l << ' ' << r << ' ' << v[p[l]] << ' ' << v[p[r]] << endl;
    int ans = inf;
    for(int i = 0; i < n; i++)
        if(v[i] >= v[p[r]])
            ans = min(ans, c[i]);
    if(ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}