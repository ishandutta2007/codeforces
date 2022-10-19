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
const ll M = 1000000007;

int n;
vector<int> g[N];

int q[N];
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
}

ll qq[N];

void solv()
{
    scanf("%d", &n);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int m;
    scanf("%d", &m);
    vector<int> v;
    for (int i = 1; i <= m; ++i)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(all(v));

    dfs(1, 1);
    for (int x = 1; x <= n; ++x)
    {
        qq[x] = (q[x] * 1LL * (n - q[x]));
    }
    sort(qq + 1, qq + n + 1);
    ll ans = 0;
    for (int i = n; i >= 1; --i)
    {
        qq[i] %= M;
        ll yans = qq[i];
        if (!v.empty())
        {
            yans = (yans * 1LL * v.back()) % M;
            v.pop_back();
        }
        while (sz(v) >= i - 1)
        {
            yans = (yans * 1LL * v.back()) % M;
            v.pop_back();
        }
        ans = (ans + yans) % M;
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}