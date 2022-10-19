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
const int N = 200005, M = 1000000009;

int n;
vector<int> g[N];
int a[N];

bool z;
ll dfs(int x, ll u)
{
    ll t = 0;
    if (g[x].empty())
        t = u;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        t += dfs(h, u);
        t = min(t, N * 1LL * M);
        if (!z)
            return 0;
    }
    t -= a[x];
    if (t < 0)
        z = false;
    return t;
}

bool stg(ll u)
{
    z = true;
    dfs(1, u);
    return z;
}

void solv()
{
    scanf("%d", &n);
    for (int x = 2; x <= n; ++x)
    {
        int p;
        scanf("%d", &p);
        g[p].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    ll l = 0, r = N * 1LL * M;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}