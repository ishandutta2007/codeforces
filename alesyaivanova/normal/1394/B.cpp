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
const int T = 12;
bool kek[T][T][T][T];
vector<pii> g[maxn];
vector<pii> q[maxn];
int n, m, k;
int ans;

void gen(vector<int>& cur)
{
    if ((int)cur.size() == k)
    {
//        cout << "!     ";
//        for (int e : cur)
//            cout << e << " ";
//        cout << "\n";
        ans++;
        return;
    }
    int x = (int)cur.size() + 1;
    for (int i = 0; i < x; i++)
    {
        if (kek[x][i][x][i])
            continue;
        bool fl = 1;
        for (int e = 0; e < (int)cur.size(); e++)
        {
            if (kek[e + 1][cur[e]][x][i])
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            cur.pb(i);
            gen(cur);
            cur.pop_back();
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(c, b);
    }
    for (int v = 0; v < n; v++)
    {
        sort(all(g[v]));
        int x = g[v].size();
        for (int i = 0; i < x; i++)
            q[g[v][i].ss].pb(x, i);
    }
    for (int v = 0; v < n; v++)
    {
        sort(all(q[v]));
        for (int i = 1; i < (int)q[v].size(); i++)
        {
            if (q[v][i] == q[v][i - 1])
                kek[q[v][i].ff][q[v][i].ss][q[v][i].ff][q[v][i].ss] = 1;
        }
        uniq(q[v]);
        for (int i = 0; i < (int)q[v].size(); i++)
            for (int e = 0; e < (int)q[v].size(); e++)
        {
            if (e == i)
                continue;
//            cout << " " << q[v][i].ff << " " << q[v][i].ss << " " << q[v][e].ff << " " << q[v][e].ss << "\n";
            kek[q[v][i].ff][q[v][i].ss][q[v][e].ff][q[v][e].ss] = 1;
        }
    }
    vector<int> cur;
    gen(cur);
    cout << ans;
}