#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if ((n & (n - 1)) == 0) {
        cout << 0 << '\n';
    } else {
        int k = 0;
        while ((1 << k + 1) <= n) {
            k++;
        }
        n ^= 1 << k;

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int j = i + 1;
            if (j >= k) {
                j -= k;
            }
            if (n & (1 << j)) {
                ans |= 1 << i;
            }
        }
        cout << ans << '\n';
    }
}