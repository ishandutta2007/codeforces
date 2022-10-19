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
const int N = 1000006;

int n;
char a[N];

int z;
int t[N][26];
vector<int> g[N];
int dp[N][2];
bool c[N];

void dfs(int x, int y)
{
    for (int i = 0; i < 26; ++i)
    {
        if (t[x][i] && t[y][i])
        {
            g[t[x][i]].push_back(t[y][i]);
            g[t[y][i]].push_back(t[x][i]);
            dfs(t[x][i], t[y][i]);
        }
    }
}

void dfs1(int x)
{
    c[x] = true;
    dp[x][1] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        dfs1(h);
        dp[x][0] += max(dp[h][1], dp[h][0]);
        dp[x][1] += dp[h][0];
    }
}

void solv()
{
    for (int i = 0; i <= z; ++i)
    {
        memset(t[i], 0, sizeof t[i]);
        g[i].clear();
        c[i] = false;
        dp[i][0] = dp[i][1] = 0;
    }
    z = 0;
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        scanf(" %s", a);
        n = strlen(a);
        int pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!t[pos][a[i] - 'a'])
            {
                t[pos][a[i] - 'a'] = ++z;
            }
            pos = t[pos][a[i] - 'a'];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (t[0][i])
        {
            dfs(0, t[0][i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= z; ++i)
    {
        if (!c[i])
        {
            dfs1(i);
            ans += max(dp[i][0], dp[i][1]);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}