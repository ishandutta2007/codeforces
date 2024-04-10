#include <algorithm>
#include <cstdio>
#include <cstring>
#define Mod 1000000007

using namespace std;

int Dp[2][200005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

        Dp[0][0] = 1;

        int ans = 0;
        for (int i = 1, u = 1; ; ++i, u ^= 1) {
            memset(Dp[u], 0, sizeof Dp[u]);
            int limit = min(i * (i - 1) / 2, N);
            for (int j = 0; j <= N; ++j) {
                int newj = j + i, news = i * (i - 1) / 2 - j;
                if (newj <= N && news <= M) {
                    Dp[u][newj] = Dp[u ^ 1][j];
                    if (Dp[u][newj] >= Mod)
                        Dp[u][newj] -= Mod;
                }

                news = i * (i - 1) / 2 - j + i;
                if (news <= M) {
                    Dp[u][j] += Dp[u ^ 1][j];
                    if (Dp[u][j] >= Mod)
                        Dp[u][j] -= Mod;
                }
            }

            int s = 0;
            for (int j = 0; j <= N; ++j) {
                s += Dp[u][j];
                if (s >= Mod)
                    s -= Mod;
            }

            if (s == 0)
                break;

            ans = s;
        }

        printf("%d\n", ans);
}