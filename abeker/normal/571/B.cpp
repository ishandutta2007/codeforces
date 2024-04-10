#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 300005;
const int MAXK = 5005;
const ll INF = (ll)2e15;

int N, K;
int a[MAXN];
ll dp[MAXK][3];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

ll solve() {
    sort(a, a + N);
    int c = 0;
    if (N < 2 * K) {
        for (int i = 1; i <= N - K; i++)
            dp[i][1] = dp[i][2] = INF;
        c = 2;
        for (int i = 2; i <= N; i++) {
            c = (c + 1) % 3;
            for (int j = 0; j <= N - K; j++) {
                dp[j][c] = dp[j][(c + 2) % 3];
                if (j) dp[j][c] = min(dp[j][c], dp[j - 1][(c + 1) % 3] + (ll)(a[i - 1] - a[i - 2]));
            }
        } 
    }
    else {
        for (int i = 0; i <= K - N % K; i++) {
            c ^= 1;
            for (int j = 0; j <= N % K; j++) {
                int hi = (i + j) * (N / K) + j;
                if (i || j) dp[j][c] = INF;
                if (i) dp[j][c] = dp[j][c ^ 1] + (ll)(a[hi - 1] - a[hi - N / K]);
                if (j) dp[j][c] = min(dp[j][c], dp[j - 1][c] + (ll)(a[hi - 1] - a[hi - N / K - 1]));
            }
        }
    }
    return dp[N % K][c];
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}