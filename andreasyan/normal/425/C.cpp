#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 303;

int n, m, s, e;
int a[N];
int b[N];
vector<int> v[N];

int dp[N][M];
int k[N];

void solv()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
        v[b[i]].push_back(i);
    }
    for (int i = 0; i < N; ++i)
        v[i].push_back(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            dp[i][j] = N;
        }
    }
    dp[0][0] = 0;
    for (int q = 0; q < M - 1; ++q)
    {
        for (int i = 0; i < N; ++i)
            k[i] = v[i].size() - 1;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i][q] == N)
                continue;
            dp[i + 1][q] = min(dp[i + 1][q], dp[i][q]);
            while (k[a[i + 1]] > 0 && v[a[i + 1]][k[a[i + 1]] - 1] > dp[i][q])
                --k[a[i + 1]];
            dp[i + 1][q + 1] = min(dp[i + 1][q + 1], v[a[i + 1]][k[a[i + 1]]]);
        }
    }
    int ans = 0;
    for (int q = 0; q < M; ++q)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dp[i][q] == N)
                continue;
            if (s - q * e - i - dp[i][q] >= 0)
                ans = max(ans, q);
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}