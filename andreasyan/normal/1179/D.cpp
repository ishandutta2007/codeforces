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
const int N = 500005;
const ll INF = 1000000009000000009;

int n;
vector<int> g[N];

ll ans;
ll dp[N];
int q[N];

bool so(int x, int y)
{
    return q[x] > q[y];
}

struct ban
{
    int h;
    ll k, b;
    ban(){}
    ban(int h, ll k, ll b)
    {
        this->h = h;
        this->k = k;
        this->b = b;
    }
};
double hat(const ban& t1, const ban& t2)
{
    return (t2.b - t1.b) / (double)(t1.k - t2.k);
}

void dfs(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }

    if (q[x] == 1)
        dp[x] = 1;
    else
    {
        dp[x] = INF;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            dp[x] = min(dp[x], (q[x] - q[h]) * 1LL * (q[x] - q[h]) + dp[h]);
        }
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        ans = min(ans, dp[h] + (n - q[h]) * 1LL * (n - q[h]));
    }

    sort(all(g[x]), so);
    vector<ban> v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;

        int l = 0, r = sz(v) - 2;
        int j = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (hat(v[m], v[m + 1]) <= q[h])
            {
                j = m + 1;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        for (int k = j - 2; k <= j + 2; ++k)
        {
            if (0 <= k && k < sz(v))
            {
                int h2 = v[k].h;
                ans = min(ans, dp[h] + dp[h2] + (n - q[h] - q[h2]) * 1LL * (n - q[h] - q[h2]));
            }
        }

        ban u(h, -2 * (n - q[h]), dp[h] + q[h] * 1LL * q[h]);
        if (!v.empty() && v.back().k == u.k)
        {
            if (v.back().b <= u.b)
                continue;
            v.pop_back();
        }
        while (sz(v) >= 2 && (hat(v[sz(v) - 2], v.back()) > hat(v.back(), u)))
            v.pop_back();
        v.push_back(u);
    }

    v.clear();
    for (int i = sz(g[x]) - 1; i >= 0; --i)
    {
        int h = g[x][i];
        if (h == p)
            continue;

        int l = 0, r = sz(v) - 2;
        int j = sz(v) - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (hat(v[m], v[m + 1]) <= q[h])
            {
                j = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        for (int k = j - 2; k <= j + 2; ++k)
        {
            if (0 <= k && k < sz(v))
            {
                int h2 = v[k].h;
                ans = min(ans, dp[h] + dp[h2] + (n - q[h] - q[h2]) * 1LL * (n - q[h] - q[h2]));
            }
        }

        ban u(h, -2 * (n - q[h]), dp[h] + q[h] * 1LL * q[h]);
        if (!v.empty() && v.back().k == u.k)
        {
            if (v.back().b <= u.b)
                continue;
            v.pop_back();
        }
        while (sz(v) >= 2 && (hat(v[sz(v) - 2], v.back()) < hat(v.back(), u)))
            v.pop_back();
        v.push_back(u);
    }
}

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

    ans = INF;
    dfs(1, 1);

    cout << (n * 2LL * n - ans - n) / 2 << "\n";
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