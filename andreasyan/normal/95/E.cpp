#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 100005;

bool stg(int x)
{
    while (x)
    {
        if (x % 10 != 7 && x % 10 != 4)
            return false;
        x /= 10;
    }
    return true;
}

int n, m;
vector<int> g[N];

bool c[N];
int q;
void dfs(int x)
{
    c[x] = true;
    ++q;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
    }
}

int a[N];

int dp[N];
int ndp[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            q = 0;
            dfs(x);
            ++a[q];
        }
    }

    for (int j = 1; j <= n; ++j)
        dp[j] = N;
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            continue;
        for (int j = 0; j <= n; ++j)
            ndp[j] = N;
        for (int j = 0; j <= n; ++j)
        {
            if (dp[j] == N)
                continue;
            for (int u = 0; u <= a[i]; ++u)
            {
                ndp[j + u * i] = min(ndp[j + u * i], dp[j] + u);
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    int ans = N;
    for (int i = 1; i <= n; ++i)
    {
        if (stg(i))
            ans = min(ans, dp[i]);
    }
    if (ans == N)
        printf("-1\n");
    else
        printf("%d\n", ans - 1);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}