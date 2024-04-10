#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define mp make_pair
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int n, m, k;
vector<int> g[maxn];
vector<int> rg[maxn];
int d[maxn];
int p[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        rg[b].pb(a);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
        d[i] = -1;
    d[p[k - 1]] = 0;
    queue<int> q;
    q.push(p[k - 1]);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int to : rg[v])
        {
            if (d[to] == -1)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    int mi = 0, ma = 0;
    for (int i = 0; i < k - 1; i++)
    {
        int v = p[i], u = p[i + 1];
        if (d[v] != d[u] + 1)
        {
            mi++;
            ma++;
            continue;
        }
        int cnt = 0;
        for (int to : g[v])
        {
            if (d[v] == d[to] + 1)
                cnt++;
        }
        if (cnt >= 2)
            ma++;
    }
    cout << mi << " " << ma;
}