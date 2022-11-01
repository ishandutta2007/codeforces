#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

char A[NMAX];
unsigned dp[NMAX];

unsigned Pow(unsigned x, int y) {
    unsigned ret = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) ret *= x;
        x *= x;
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d\n%s", &n, A + 1);

    reverse(A + 1, A + n + 1);
    
    dp[0] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int m = min(i + 1, n - i + 2);
        if (A[i] == '?') {
            cnt++;
            int aux1 = 0, aux2;
            for (int j = 0; j < m; ++j) {
                aux2 = dp[j];
                dp[j] = aux1 + dp[j + 1];
                aux1 = aux2;
            }
        } else {
            cnt--;
            memmove(dp, dp + 1, sizeof(unsigned) * m);
            dp[m] = 0;
        }
        if (cnt < 0) {
            puts("0");
            return 0;
        }
    }
    if (cnt % 2) {
        puts("0");
        return 0;
    }
    cnt /= 2;

    printf("%u\n", dp[0] * Pow(25, cnt));
}