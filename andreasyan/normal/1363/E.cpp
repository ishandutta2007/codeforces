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
int a[N], b[N], c[N];
vector<int> g[N];

ll dp[N];

int q[N][2];

void dfs(int x, int p)
{
    a[x] = min(a[x], a[p]);
    q[x][0] = q[x][1] = 0;
    if (b[x] != c[x])
        ++q[x][b[x]];
    dp[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x] += dp[h];
        q[x][0] += q[h][0];
        q[x][1] += q[h][1];
    }
    int minu = min(q[x][0], q[x][1]);
    dp[x] += minu * 2LL * a[x];
    q[x][0] -= minu;
    q[x][1] -= minu;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    if (q[1][0] || q[1][1])
        printf("-1\n");
    else
        printf("%lld\n", dp[1]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}