#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000005;
const int64_t INF = 1LL << 62;

int A[NMAX];
int64_t dp1[NMAX], dp2[NMAX], dp3[NMAX];

vector<int> getDivisors(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ret.push_back(n);
    }
    return ret;
}

int64_t solve(int left, int right, int a, int b) {
    int64_t ans = INF;
    for (int t = -1; t <= 1; ++t) {
        vector<int> divs = getDivisors(A[left] + t);
        for (int dv: divs) {
            dp1[left] = (t == 0 ? 0: b);
            dp2[left] = dp3[left] = INF;
            for (int i = left + 1; i < right; ++i) {
                dp1[i] = dp2[i] = dp3[i] = INF;
                if (A[i] % dv == 0) {
                    dp1[i] = dp1[i - 1];
                    dp2[i] = min(dp2[i - 1], dp1[i - 1]) + a;
                    dp3[i] = min(dp3[i - 1], dp2[i - 1]);
                } else if ((A[i] + 1) % dv == 0 || (A[i] - 1) % dv == 0) {
                    dp1[i] = dp1[i - 1] + b;
                    dp2[i] = min(dp2[i - 1], dp1[i - 1]) + a;
                    dp3[i] = min(dp3[i - 1], dp2[i - 1]) + b;
                } else {
                    dp2[i] = min(dp2[i - 1], dp1[i - 1]) + a;
                }
            }
            ans = min(ans, dp1[right - 1]);
            ans = min(ans, dp2[right - 1]);
            ans = min(ans, dp3[right - 1]);
        }
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int64_t ans = solve(0, n, a, b);
    reverse(A + 0, A + n);
    ans = min(ans, solve(0, n, a, b));

    cout << ans << '\n';
}