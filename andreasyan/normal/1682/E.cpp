#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m;
int p[N];
vector<int> g[N], gi[N];

bool c[N];
int u[N];

vector<int> ans;
void dfs(int x, int p)
{
    c[x] = true;
    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (u[h] > u[x])
            v.push_back(m_p(u[h] - u[x], m_p(h, hi)));
        else
            v.push_back(m_p(n + 5 - u[x] + u[h], m_p(h, hi)));
    }

    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se.fi == p)
            ans.push_back(v[i].se.se);
        else
            dfs(v[i].se.fi, x);
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;

        int t = 1;
        int x = i;
        while (!c[x])
        {
            c[x] = true;
            u[x] = ++t;
            x = p[x];
        }
    }

    memset(c, false, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;

        dfs(i, i);
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}