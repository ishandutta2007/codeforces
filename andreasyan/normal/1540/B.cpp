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
const int N = 502, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int c[N][N];
int rc[N][N];
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            rc[i][j] = ast(c[i][j], M - 2);
        }
    }
}

int n;
vector<int> g[N];

int d[N];
int tin[N], tout[N], ti;
int p0[N];
int lca[N][N];
vector<int> v[N];
void dfs(int x, int p)
{
    tin[x] = ++ti;
    p0[x] = p;
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    v[x].clear();
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        for (int j = 0; j < sz(v[x]); ++j)
        {
            for (int k = 0; k < sz(v[h]); ++k)
            {
                lca[v[x][j]][v[h][k]] = lca[v[h][k]][v[x][j]] = x;
            }
        }
        for (int k = 0; k < sz(v[h]); ++k)
            v[x].push_back(v[h][k]);
    }
    v[x].push_back(x);
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

vector<int> rands(int r)
{
    vector<int> ans;
    vector<int> v;
    v.push_back(r);
    while (!v.empty())
    {
        sort(all(v));
        int x = v[rnf() % sz(v)];
        ans.push_back(x);
        vector<int> vv;
        for (int i = 0; i < sz(v); ++i)
        {
            if (v[i] == x)
                continue;
            vv.push_back(v[i]);
        }
        v = vv;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p0[x])
                continue;
            v.push_back(h);
        }
    }
    return ans;
}

int dp[N][N][2];
int dpp[N][N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            for (int z = 0; z < 2; ++z)
            {
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][z] * 1LL * ast(2, M - 2)) % M;
                dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i][j][z] * 1LL * ast(2, M - 2)) % M;
            }
        }
    }
    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 1; j < N - 1; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                dpp[i][j] = (dpp[i][j] + dp[i][k][0]) % M;
            }
        }
    }

    int ans = 0;

    for (int r = 1; r <= n; ++r)
    {
        ti = 0;
        dfs(r, r);
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y < x; ++y)
            {
                if (isp(x, y))
                {
                    ans = (ans + rc[n][1]) % M;
                    continue;
                }
                if (isp(y, x))
                    continue;
                int t = 1;
                d[x] -= d[lca[x][y]];
                d[y] -= d[lca[x][y]];
                //t = (t * 1LL * c[d[x] + d[y] - 1][d[x]]) % M;
                //t = (t * 1LL * rc[d[x] + d[y]][d[x]]) % M;
                t = dpp[d[x]][d[y]];
                t = (t * 1LL * rc[n][1]) % M;
                ans = (ans + t) % M;
                double u = c[d[x] + d[y] - 1][d[x]] / (double)c[d[x] + d[y]][d[x]];
                d[x] += d[lca[x][y]];
                d[y] += d[lca[x][y]];

                /*int q = 0;
                for (int ii = 0; ii < 10000; ++ii)
                {
                    vector<int> v = rands(r);
                    for (int i = 0; i < sz(v); ++i)
                    {
                        if (v[i] == y)
                            break;
                        if (v[i] == x)
                        {
                            ++q;
                            break;
                        }
                    }
                }
                if (abs(u - q / (double)10000) > 0.01)
                {
                    cout << r << ' ' << x << ' ' << y << "\n";
                    cout << u << ' ' << q / (double)10000 << "\n";
                }*/
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}