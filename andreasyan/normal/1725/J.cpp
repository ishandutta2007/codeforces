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

int n;
vector<pair<int, int> > g[N];

ll dp[N];
ll d[N];
void dfs0(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        dfs0(h, x);
        dp[x] = max(dp[x], dp[h]);
    }
    ll max1 = 0, max2 = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        ll u  = d[h] + g[x][i].se;
        if (u >= max1)
        {
            max2 = max1;
            max1 = u;
        }
        else if (u >= max2)
            max2 = u;
    }
    d[x] = max1;
    dp[x] = max(dp[x], max1 + max2);
}

ll ans;
void dfs1(int x, int p, ll pd, ll dpp)
{
    ll ymax1 = 0, ymax2 = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        ll u;
        if (h == p)
            u = dpp;
        else
            u = dp[h];
        if (u >= ymax1)
        {
            ymax2 = ymax1;
            ymax1 = u;
        }
        else if (u >= ymax2)
            ymax2 = u;
    }

    ll max1 = 0, max2 = 0, max3 = 0, max4 = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        ll u;
        if (h == p)
            u = pd + g[x][i].se;
        else
            u = d[h] + g[x][i].se;
        if (u >= max1)
        {
            max4 = max3;
            max3 = max2;
            max2 = max1;
            max1 = u;
        }
        else if (u >= max2)
        {
            max4 = max3;
            max3 = max2;
            max2 = u;
        }
        else if (u >= max3)
        {
            max4 = max3;
            max3 = u;
        }
        else if (u >= max4)
            max4 = u;
    }

    ans = max(ans, max1 + max2 + max3 + max4);

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        ll ydp;
        if (dp[h] == ymax1)
            ydp = ymax2;
        else
            ydp = ymax1;

        if (d[h] + g[x][i].se == max1)
            ydp = max(ydp, max2 + max3);
        else if (d[h] + g[x][i].se == max2)
            ydp = max(ydp, max1 + max3);
        else
            ydp = max(ydp, max1 + max2);
        ans = max(ans, g[x][i].se * 2 + dp[h] + ydp);

        ll yd;
        if (d[h] + g[x][i].se == max1)
            yd = max2;
        else
            yd = max1;
        dfs1(h, x, yd, ydp);
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    dfs0(1, 1);
    dfs1(1, 1, 0, 0);

    ans *= -1;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            ans += g[x][i].se;
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