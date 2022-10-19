#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;
const int M = 1000000007;

int n, d;
int g[N];
vector<int> a[N];

vector<int> v[N];

bool c[N];

int dp[N];
void dfs(int x, int p)
{
    dp[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (!c[h])
            continue;
        dfs(h, x);
        dp[x] = (dp[x] * 1LL * (dp[h] + 1)) % M;
    }
}

int main()
{
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &g[i]);
        v[g[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i - d - 1 >= 0)
        {
            for (int j = 0; j < v[i - d - 1].size(); ++j)
                c[v[i - d - 1][j]] = false;
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            c[x] = true;
            dfs(x, x);
            ans = (ans + dp[x]) % M;
        }
    }
    printf("%d\n", ans);
    return 0;
}
//tpmp