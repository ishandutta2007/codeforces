#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t f(int64_t n) {
    if (n == 1) {
        return 1;
    }
    int64_t ans = n;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ans /= i;
            ans *= i - 1;
        }
    }
    if (n > 1) {
        ans /= n;
        ans *= n - 1;
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
    cin.tie(0);

    int64_t n, k;
    cin >> n >> k;

    for (int64_t i = 1; i <= k; i += 2) {
        n = f(n);
        if (n == 1) {
            break;
        }
    }
    cout << n % 1000000007 << '\n';
}