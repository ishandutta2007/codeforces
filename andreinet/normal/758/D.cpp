#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int64_t LINF = 1LL << 61;
const int NMAX = 65;

int64_t dp[NMAX];
char A[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int base;
    cin >> base >> (A + 1);
    int n = strlen(A + 1);

    for (int i = 1; i <= n; ++i) {
        dp[i] = LINF;
    }
    for (int i = 0; i < n; ++i) {
        int64_t fct = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (j > i + 1 && A[i + 1] == '0') {
                break;
            }
            if (fct <= LINF / 10) {
                fct *= 10;
            } else {
                fct = LINF;
            }
            if (fct <= LINF - (A[j] - '0')) {
                fct += A[j] - '0';
            } else {
                fct = LINF;
            }
            if (fct >= LINF || fct >= base) {
                break;
            }
            int64_t xdp = dp[i];
            if (xdp <= LINF / base) {
                xdp *= base;
            } else {
                xdp = LINF;
            }
            if (xdp <= LINF - fct) {
                xdp += fct;
            } else {
                xdp = LINF;
            }
            if (xdp >= LINF) {
                break;
            }
            dp[j] = min(dp[j], xdp);
        }
    }
    cout << dp[n] << '\n';
}