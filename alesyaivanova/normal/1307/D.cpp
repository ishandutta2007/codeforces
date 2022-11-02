#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int n, m, k;
pii a[maxn];
vector<int> g[maxn];
int d[maxn][2];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i].ss;
        a[i].ss--;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < n; i++)
    {
        d[i][0] = -1;
        d[i][1] = -1;
    }
    queue<int> q;
    d[0][0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int to : g[v])
        {
            if (d[to][0] == -1)
            {
                d[to][0] = d[v][0] + 1;
                q.push(to);
            }
        }
    }
    d[n - 1][1] = 0;
    q.push(n - 1);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int to : g[v])
        {
            if (d[to][1] == -1)
            {
                d[to][1] = d[v][1] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 0; i < k; i++)
        a[i].ff = d[a[i].ss][0];
//    for (int i = 0; i < n; i++)
//        cout << " " << d[i][0] << " " << d[i][1] << "\n";
    sort(a, a + k);
    int ma = -1e9;
    int ans = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        int v = a[i].ss;
        int cur = d[v][0] + ma + 1;
        //cout << "     " << cur << "\n";
        ans = max(ans, cur);
        ma = max(ma, d[v][1]);
    }
    cout << min(ans, d[n - 1][0]);
}