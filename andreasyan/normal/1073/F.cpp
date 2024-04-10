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
const int N = 200005, INF = 100000008;

int n;
vector<int> g[N];
vector<int> gg[N];

int d[N];
void dfs0(int x, int p)
{
    d[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

void dfs1(int x, int p, int dp)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            gg[x].push_back(dp);
        else
            gg[x].push_back(d[h]);
    }
    int max1 = -INF, max2 = -INF;
    for (int i = 0; i < g[x].size(); ++i)
    {
        if (gg[x][i] >= max1)
        {
            max2 = max1;
            max1 = gg[x][i];
        }
        else if (gg[x][i] > max2)
            max2 = gg[x][i];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (d[h] == max1)
            dfs1(h, x, max2 + 1);
        else
            dfs1(h, x, max1 + 1);
    }
}

pair<int, int> ans;

pair<int, int> dp[N];
int udp[N];
void dfs2(int x, int p)
{
    dp[x] = m_p(-INF, -INF);
    udp[x] = -1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs2(h, x);
        if (udp[h] != -1)
        {
            if (m_p(dp[h].fi + 1, dp[h].se) > dp[x])
            {
                dp[x] = m_p(dp[h].fi + 1, dp[h].se);
                udp[x] = udp[h];
            }
        }
    }

    {
        pair<int, int> max1 = m_p(-INF, -INF), max2 = m_p(-INF, -INF);
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (dp[h] >= max1)
            {
                max2 = max1;
                max1 = dp[h];
            }
            else if (dp[h] > max2)
                max2 = dp[h];
        }
        pair<int, int> t = m_p(max1.fi + max2.fi + 1, max1.se + max2.se);
        ans = max(ans, t);
    }

    if (sz(g[x]) >= 3)
    {
        int max1 = -INF, max2 = -INF, max3 = -INF;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (gg[x][i] >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = gg[x][i];
            }
            else if (gg[x][i] >= max2)
            {
                max3 = max2;
                max2 = gg[x][i];
            }
            else if (gg[x][i] > max3)
            {
                max3 = gg[x][i];
            }
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            pair<int, int> t;
            if (gg[x][i] == max1)
                t = m_p(dp[h].fi + 1, dp[h].se + max2 + max3);
            else if (gg[x][i] == max2)
                t = m_p(dp[h].fi + 1, dp[h].se + max1 + max3);
            else
                t = m_p(dp[h].fi + 1, dp[h].se + max1 + max2);
            ans = max(ans, t);
        }
    }

    if (sz(g[x]) >= 3)
    {
        pair<int, int> t = m_p(1, 0);
        int max1 = -INF, max2 = -INF;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (gg[x][i] >= max1)
            {
                max2 = max1;
                max1 = gg[x][i];
            }
            else if (gg[x][i] > max2)
                max2 = gg[x][i];
        }
        t.se = max1 + max2;
        if (t > dp[x])
        {
            dp[x] = t;
            udp[x] = x;
        }
    }
}

int ans1, ans2;
void dfs3(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs3(h, x);
    }

    {
        pair<int, int> max1 = m_p(-INF, -INF), max2 = m_p(-INF, -INF);
        int umax1 = -1, umax2 = -1;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (dp[h] >= max1)
            {
                umax2 = umax1;
                umax1 = h;
                max2 = max1;
                max1 = dp[h];
            }
            else if (dp[h] > max2)
            {
                umax2 = h;
                max2 = dp[h];
            }
        }
        pair<int, int> t = m_p(max1.fi + max2.fi + 1, max1.se + max2.se);
        if (ans == t)
        {
            ans1 = udp[umax1];
            ans2 = udp[umax2];
        }
    }

    if (sz(g[x]) >= 3)
    {
        int max1 = -INF, max2 = -INF, max3 = -INF;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (gg[x][i] >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = gg[x][i];
            }
            else if (gg[x][i] >= max2)
            {
                max3 = max2;
                max2 = gg[x][i];
            }
            else if (gg[x][i] > max3)
            {
                max3 = gg[x][i];
            }
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            pair<int, int> t;
            if (gg[x][i] == max1)
                t = m_p(dp[h].fi + 1, dp[h].se + max2 + max3);
            else if (gg[x][i] == max2)
                t = m_p(dp[h].fi + 1, dp[h].se + max1 + max3);
            else
                t = m_p(dp[h].fi + 1, dp[h].se + max1 + max2);
            if (ans == t)
            {
                ans1 = x;
                ans2 = udp[h];
            }
        }
    }
}

vector<int> v;
bool dfs4(int x, int p, int y)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (dfs4(h, x, y))
            return true;
    }
    v.pop_back();
    return false;
}

int dfs5(int x, int p)
{
    int maxu = -INF;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        maxu = max(maxu, gg[x][i]);
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (maxu == gg[x][i])
            return dfs5(h, x);
    }
    return x;
}

int yans1, yans2, yans3, yans4;
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

    dfs0(1, 1);
    dfs1(1, 1, 0);
    dfs2(1, 1);
    dfs3(1, 1);

    dfs4(ans1, ans1, ans2);

    {
        int max1 = -INF, max2 = -INF;
        int umax1 = -1, umax2 = -1;
        for (int i = 0; i < g[ans1].size(); ++i)
        {
            int h = g[ans1][i];
            if (h == v[1])
                continue;
            if (gg[ans1][i] >= max1)
            {
                umax2 = umax1;
                umax1 = h;
                max2 = max1;
                max1 = gg[ans1][i];
            }
            else if (gg[ans1][i] > max2)
            {
                umax2 = h;
                max2 = gg[ans1][i];
            }
        }
        yans1 = dfs5(umax1, ans1);
        yans3 = dfs5(umax2, ans1);
    }
    swap(ans1, ans2);
    reverse(all(v));
    {
        int max1 = -INF, max2 = -INF;
        int umax1 = -1, umax2 = -1;
        for (int i = 0; i < g[ans1].size(); ++i)
        {
            int h = g[ans1][i];
            if (h == v[1])
                continue;
            if (gg[ans1][i] >= max1)
            {
                umax2 = umax1;
                umax1 = h;
                max2 = max1;
                max1 = gg[ans1][i];
            }
            else if (gg[ans1][i] > max2)
            {
                umax2 = h;
                max2 = gg[ans1][i];
            }
        }
        yans2 = dfs5(umax1, ans1);
        yans4 = dfs5(umax2, ans1);
    }
    cout << yans1 << ' ' << yans2 << "\n";
    cout << yans3 << ' ' << yans4 << "\n";
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