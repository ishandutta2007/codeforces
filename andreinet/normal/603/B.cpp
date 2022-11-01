#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 1000005, MOD = 1e9 + 7;

int A[NMAX];
bool used[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; ++i)
        A[i] = (int64_t) i * k % n;

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (!used[i]) {
            ans = (int64_t) ans * n % MOD;
            for (int j = i; !used[j]; j = A[j]) {
                used[j] = true;
            }
        }
    }
    if (k == 1) ans = (int64_t) ans * n % MOD;

    cout << ans << '\n';
}