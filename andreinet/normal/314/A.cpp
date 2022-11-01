#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 200011;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int64_t sum = 0;
    for (int i = 1, j = 1; i <= n; ++i, ++j) {
        int x;
        cin >> x;

        int64_t c = sum - (int64_t) (i - 1) * (n - i) * x;
        if (c < k) {
            cout << j << '\n';
            i--;
            n--;
        } else {
            sum += (int64_t) (i - 1) * x;
        }
    }
}