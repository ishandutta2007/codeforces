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
const int N = 100005;

int n, L;
ll S;
int w[N];

int p[N];
vector<int> a[N];

vector<int> v;

ll t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll s;
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
    {
        if (t[pos] <= s)
        {
            s -= t[pos];
            return -1;
        }
    }
    if (tl == tr)
    {
        return tl + 1;
    }
    int m = (tl + tr) / 2;
    int u = qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    if (u != -1)
        return u;
    return qry(tl, m, l, min(m, r), pos * 2);
}

int d[N];
int u[N];

void dfs(int x)
{
    d[x] = d[p[x]] + 1;
    ubd(0, n - 1, v.size(), w[x], 1);
    v.push_back(x);
    s = S;
    u[x] = qry(0, n - 1, 0, v.size() - 1, 1);
    u[x] = max(u[x], (int)v.size() - L);
    if (u[x] == -1)
        u[x] = 0;
    u[x] = v[u[x]];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
    }
    v.pop_back();
}

pair<int, int> dp[N];
void dfs1(int x)
{
    int sp = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs1(h);
        sp += dp[h].fi;
    }
    dp[x] = m_p(sp + 1, u[x]);
    int uu = -1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (d[dp[h].se] <= d[x])
        {
            if (uu == -1 || d[dp[h].se] < d[uu])
                uu = dp[h].se;
        }
    }
    if (uu != -1)
        dp[x] = m_p(sp, uu);
}

void solv()
{
    scanf("%d%d%lld", &n, &L, &S);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &p[i]);
        a[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (w[i] > S)
        {
            printf("-1\n");
            return;
        }
    }
    dfs(1);
    dfs1(1);
    printf("%d\n", dp[1].fi);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}