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
const int N = 100005, INF = 1000006;

int n;
vector<int> g[N];

int dp[N][2];
ll p[N], s[N];
void dfs(int x, int p0)
{
    dp[x][0] = dp[x][1] = INF;

    vector<pair<int, int> > v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs(h, x);
        v.push_back(m_p(dp[h][1] + 2 - dp[h][0], h));
    }
    sort(all(v));
    reverse(all(v));
    v.push_back(m_p(-1, -1));
    reverse(all(v));

    for (int i = 1; i < sz(v); ++i)
    {
        int h = v[i].se;
        p[i] = p[i - 1] + dp[h][1] + 2;
    }
    s[sz(v)] = 0;
    for (int i = sz(v) - 1; i >= 1; --i)
    {
        int h = v[i].se;
        s[i] = s[i + 1] + dp[h][0];
    }

    for (int i = 0; i < sz(v); i += 2)
    {
        dp[x][1] = min(dp[x][1] * 1LL, p[i] + s[i + 1]);
        if (i)
            dp[x][0] = min(dp[x][0] * 1LL, p[i] + s[i + 1]);
    }
    for (int i = 1; i < sz(v); i += 2)
    {
        dp[x][1] = min(dp[x][1] * 1LL, p[i] + s[i + 1]);
        dp[x][0] = min(dp[x][0] * 1LL, p[i] + s[i + 1]);
    }
}

vector<deque<int> > ansvd;
void dfs1(int x, int p0, int z, int k)
{
    vector<pair<int, int> > v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        v.push_back(m_p(dp[h][1] + 2 - dp[h][0], h));
    }
    sort(all(v));
    reverse(all(v));
    v.push_back(m_p(-1, -1));
    reverse(all(v));

    for (int i = 1; i < sz(v); ++i)
    {
        int h = v[i].se;
        p[i] = p[i - 1] + dp[h][1] + 2;
    }
    s[sz(v)] = 0;
    for (int i = sz(v) - 1; i >= 1; --i)
    {
        int h = v[i].se;
        s[i] = s[i + 1] + dp[h][0];
    }

    if (z == 0)
    {
        for (int i = 0; i < sz(v); i += 2)
        {
            if (i)
            {
                if (dp[x][0] == p[i] + s[i + 1])
                {
                    for (int j = i + 1; j < sz(v); ++j)
                        dfs1(v[j].se, x, 0, 0);
                    for (int j = 3; j <= i; j += 2)
                    {
                        int u = sz(ansvd);
                        ansvd.push_back({});
                        dfs1(v[j].se, x, u, -1);
                        dfs1(v[j + 1].se, x, u, 1);
                    }
                    int u = sz(ansvd);
                    ansvd.push_back({});
                    dfs1(v[1].se, x, u, -1);
                    ansvd[u].push_back(x);
                    dfs1(v[2].se, x, u, 1);
                    return;
                }
            }
        }
        for (int i = 1; i < sz(v); i += 2)
        {
            if (dp[x][0] == p[i] + s[i + 1])
            {
                for (int j = i + 1; j < sz(v); ++j)
                    dfs1(v[j].se, x, 0, 0);
                for (int j = 2; j <= i; j += 2)
                {
                    int u = sz(ansvd);
                    ansvd.push_back({});
                    dfs1(v[j].se, x, u, -1);
                    dfs1(v[j + 1].se, x, u, 1);
                }
                int u = sz(ansvd);
                ansvd.push_back({});
                dfs1(v[1].se, x, u, -1);
                ansvd[u].push_back(x);
                return;
            }
        }
    }
    else
    {
        if (k == 1)
            ansvd[z].push_back(x);
        else
            ansvd[z].push_front(x);
        for (int i = 0; i < sz(v); i += 2)
        {
            if (p[i] + s[i + 1] == dp[x][1])
            {
                for (int j = i + 1; j < sz(v); ++j)
                    dfs1(v[j].se, x, 0, 0);
                for (int j = 1; j <= i; j += 2)
                {
                    int u = sz(ansvd);
                    ansvd.push_back({});
                    dfs1(v[j].se, x, u, -1);
                    dfs1(v[j + 1].se, x, u, 1);
                }
                return;
            }
        }
        for (int i = 1; i < sz(v); i += 2)
        {
            if (p[i] + s[i + 1] == dp[x][1])
            {
                for (int j = i + 1; j < sz(v); ++j)
                    dfs1(v[j].se, x, 0, 0);
                for (int j = 2; j <= i; j += 2)
                {
                    int u = sz(ansvd);
                    ansvd.push_back({});
                    dfs1(v[j].se, x, u, -1);
                    dfs1(v[j + 1].se, x, u, 1);
                }
                dfs1(v[1].se, x, z, k);
                return;
            }
        }
    }
}

int dfs_dist(int x, int p, int y, int d)
{
    if (x == y)
        return d;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        int u = dfs_dist(h, x, y, d + 1);
        if (u != -1)
            return u;
    }
    return -1;
}

int solv0()
{
    int ansg = N;
    int ans[20];

    int yans[20];
    for (int i = 1; i <= n; ++i)
        yans[i] = i;

    do
    {
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (yans[i] == i)
            {
                z = false;
                break;
            }
        }
        if (!z)
            continue;

        int yansg = 0;

        for (int x = 1; x <= n; ++x)
        {
            yansg += dfs_dist(x, x, yans[x], 0);
        }

        if (yansg < ansg)
        {
            ansg = yansg;
            for (int i = 1; i <= n; ++i)
                ans[i] = yans[i];
        }
    } while (next_permutation(yans + 1, yans + n + 1));

    /*printf("%d\n", ansg);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");*/

    return ansg;
}

void ka()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void gen()
{
    n = 9;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int x = 2; x <= n; ++x)
    {
        int y = rnf() % (x - 1) + 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int ans[N];

void solv()
{
    ka();
    //gen();

    dfs(1, 1);

    ansvd.clear();
    ansvd.push_back({});
    dfs1(1, 1, 0, 0);
    for (int i = 1; i < ansvd.size(); ++i)
    {
        for (int j = 0; j < sz(ansvd[i]) - 1; ++j)
        {
            ans[ansvd[i][j]] = ansvd[i][j + 1];
        }
        ans[ansvd[i].back()] = ansvd[i][0];
    }

    printf("%d\n", dp[1][0]);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return;

    if (dp[1][0] != solv0())
    {
        printf("WA\n");
        solv0();
        dfs(1, 1);
    }
    //printf("%d\n", ansg);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}