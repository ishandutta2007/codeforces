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

const int maxn = 5e5 + 9;
vector<int> g[maxn];
int n, m;
int t[maxn];
pii x[maxn];
bool used[maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        x[i].ff = t[i];
        x[i].ss = i;
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++)
    {
        int v = x[i].ss;
        int cur = 0;
        for (int to : g[v])
        {
            if (t[to] == t[v])
            {
                cout << -1;
                return 0;
            }
            if (t[to] < t[v] && !used[t[to]])
            {
                cur++;
                used[t[to]] = 1;
            }
        }
        if (cur != t[v] - 1)
        {
            cout << -1;
            return 0;
        }
        for (int to : g[v])
            used[t[to]] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << x[i].ss + 1 << " ";
}