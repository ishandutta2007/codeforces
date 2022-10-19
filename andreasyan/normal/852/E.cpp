#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
vector<int> a[N];

int dp[N];
void dfs(int x, int p)
{
    dp[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x] = (dp[x] * 1LL * dp[h]) % M;
    }
    if (!(x != p && a[x].size() == 1))
        dp[x] = (dp[x] * 2) % M;
}

int ans;

void dfs1(int x, int p, int dpp)
{
    int u = dpp;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        u = (u * 1LL * dp[h]) % M;
    }
    ans = (ans + (u * 2) % M) % M;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        int uu = (u * 1LL * ast(dp[h], M - 2)) % M;
        if (x == p && a[x].size() == 1)
            dfs1(h, x, uu);
        else
            dfs1(h, x, (uu * 2) % M);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    dfs(1, 1);
    dfs1(1, 1, 1);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}