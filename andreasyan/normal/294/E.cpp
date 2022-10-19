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
const int N = 5003;
const ll INF = 1000000009000000009;

struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};

int n;
vector<ban> a[N];
vector<int> ei[N];
pair<pair<int, int>, int> b[N];

ll sans;
void dfss(int x, int p, ll d)
{
    sans += d;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        dfss(h, x, d + a[x][i].d);
    }
}

ll dp[N];
int q[N];
void dfs0(int x, int p, int ae)
{
    q[x] = 1;
    dp[x] = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p || ei[x][i] == ae)
            continue;
        dfs0(h, x, ae);
        q[x] += q[h];
        dp[x] += dp[h];
        dp[x] += q[h] * 1LL * a[x][i].d;
    }
}

ll minu;
void dfs1(int x, int p, int ae, ll dpp, int ep, int xx)
{
    minu = min(minu, dp[x] + dpp + ep * 1LL * (q[xx] - q[x]));
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p || ei[x][i] == ae)
            continue;
        dfs1(h, x, ae, dp[x] - dp[h] - q[h] * 1LL * a[x][i].d + dpp + ep * 1LL * (q[xx] - q[x]), a[x][i].d, xx);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        a[x].push_back(ban(y, d));
        a[y].push_back(ban(x, d));
        ei[x].push_back(i);
        ei[y].push_back(i);
        b[i] = m_p(m_p(x, y), d);
    }
    for (int i = 1; i <= n; ++i)
        dfss(i, i, 0);
    sans /= 2;
    ll ans = sans;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, d;
        x = b[i].fi.fi;
        y = b[i].fi.se;
        d = b[i].se;
        dfs0(x, x, i);
        minu = INF;
        dfs1(x, x, i, 0, 0, x);
        ll minu1 = minu;
        ll dp1 = dp[x];
        dfs0(y, y, i);
        minu = INF;
        dfs1(y, y, i, 0, 0, y);
        ans = min(ans, sans - dp[y] * (n - q[y]) - dp1 * q[y] + minu * (n - q[y]) + minu1 * q[y]);
    }
    printf("%lld\n", ans);
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