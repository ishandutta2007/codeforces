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
const ll INF = 1000000009000000009;

int n;
int a[N];
vector<int> g[N];

int emax[N];
void dfs0(int x, int p)
{
    emax[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        emax[x] = max(emax[x], emax[h]);
    }
}

vector<int> gmax[N];
void dfs1(int x, int p, int pmax)
{
    int max1 = -1;
    int max2 = -1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
        {
            gmax[x].push_back(pmax);
            if (pmax >= max1)
            {
                max2 = max1;
                max1 = pmax;
            }
            else if (pmax >= max2)
                max2 = pmax;
            continue;
        }
        gmax[x].push_back(emax[h]);
        if (emax[h] >= max1)
        {
            max2 = max1;
            max1 = emax[h];
        }
        else if (emax[h] >= max2)
            max2 = emax[h];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (emax[h] == max1)
            dfs1(h, x, max(max2, a[x]));
        else
            dfs1(h, x, max(max1, a[x]));
    }
}

bool c[N];
bool cc[N];

void dfs2(int x, int p)
{
    emax[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs2(h, x);
        emax[x] = max(emax[x], emax[h]);
    }
}

vector<int> gg[N];
void dfs3(int x, int p, int pp)
{
    if (x != p && emax[x] == a[x])
    {
        gg[pp].push_back(x);
        pp = x;
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs3(h, x, pp);
    }
}

ll dp[N][2];
void dfs4(int x)
{
    ll s = 0;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        dfs4(h);
        s += dp[h][0];
    }

    dp[x][0] = dp[x][1] = INF;

    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        dp[x][1] = min(dp[x][1], s - dp[h][0] + dp[h][1]);
        dp[x][0] = min(dp[x][0], s - dp[h][0] + dp[h][1] + a[x]);
    }

    if (gg[x].empty())
    {
        dp[x][1] = 0;
        dp[x][0] = a[x];
    }
}

int ee[N];
void dfs5(int x, int p, int xx)
{
    ee[x] = xx;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs5(h, x, xx);
    }
}

ll minu[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);
    dfs1(1, 1, -1);

    ll ans = 0;
    int ymax = emax[1];

    int qymax = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (a[x] == ymax)
            ++qymax;
    }

    if (qymax == 1)
    {
        ans += ymax * 2;
        for (int x = 1; x <= n; ++x)
        {
            if (a[x] == ymax)
            {
                dfs2(x, x);
                dfs3(x, x, x);
                dfs4(x);

                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i];
                    dfs5(h, x, h);
                }

                ll s = 0;
                ll min1 = 0, min2 = 0;
                for (int i = 0; i < gg[x].size(); ++i)
                {
                    int h = gg[x][i];
                    s += dp[h][0];

                    minu[ee[h]] = min(minu[ee[h]], dp[h][1] - dp[h][0]);
                }

                for (int i = 1; i <= n; ++i)
                {
                    if (minu[i] <= min1)
                    {
                        min2 = min1;
                        min1 = minu[i];
                    }
                    else if (minu[i] <= min2)
                    {
                        min2 = minu[i];
                    }
                }

                ans += s;
                ans += min1;
                if (sz(g[x]) > 1)
                    ans += min2;
            }
        }

        cout << ans << "\n";
        return;
    }

    for (int x = 1; x <= n; ++x)
    {
        int q = 0;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (gmax[x][i] == ymax)
                ++q;
        }

        if (q >= 2)
            c[x] = true;
        else if (a[x] == ymax)
        {
            c[x] = true;
            cc[x] = true;
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (a[x] == ymax)
        {
            if (cc[x])
            {
                dfs2(x, x);
                dfs3(x, x, x);
                dfs4(x);

                ans += dp[x][0];
            }
            else
            {
                dfs2(x, x);
                dfs3(x, x, x);
                dfs4(x);

                for (int i = 0; i < gg[x].size(); ++i)
                {
                    int h = gg[x][i];
                    if (c[h])
                        continue;
                    ans += dp[h][0];
                }
            }
        }
        else if (c[x])
        {
            a[x] = ymax;

            dfs2(x, x);
            dfs3(x, x, x);
            dfs4(x);

            for (int i = 0; i < gg[x].size(); ++i)
            {
                int h = gg[x][i];
                if (c[h])
                    continue;
                ans += dp[h][0];
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}