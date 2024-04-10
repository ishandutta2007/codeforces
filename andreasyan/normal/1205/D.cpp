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
const int N = 1003;

int n;
pair<int, int> b[N];
vector<int> g[N];
vector<int> gi[N];
int ans[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

int c[N];

void dfs(int x, int p)
{
    int qq = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        ans[gi[x][i]] = 1 + qq;
        qq += q[h];
    }
}

void dfs2(int x, int p, int u)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs2(h, x, u);
        ans[gi[x][i]] *= u;
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        b[i] = m_p(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    dfs0(1, 1);
    int r = dfsc(1, 1, 1);
    dfs0(r, r);

    vector<pair<int, int> > v;
    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        v.push_back(m_p(q[h], h));
    }
    sort(all(v));
    reverse(all(v));
    int q1 = 0, q2 = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (q1 <= q2)
        {
            c[v[i].se] = 1;
            q1 += v[i].fi;
        }
        else
        {
            c[v[i].se] = 2;
            q2 += v[i].fi;
        }
    }

    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        dfs(h, r);
    }

    int qq = 0;
    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        if (c[h] == 1)
        {
            ans[gi[r][i]] = 1 + qq;
            qq += q[h];
        }
    }

    qq = 0;
    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        if (c[h] == 2)
        {
            ans[gi[r][i]] = 1 + qq;
            qq += q[h];
        }
    }

    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        if (c[h] == 2)
        {
            ans[gi[r][i]] *= (q1 + 1);
            dfs2(h, r, (q1 + 1));
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        assert(ans[i] <= 1000000);
        cout << b[i].fi << ' ' << b[i].se << ' ' << ans[i] << "\n";
    }
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