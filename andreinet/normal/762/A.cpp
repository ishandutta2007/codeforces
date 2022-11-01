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

    int64_t n;
    int k;
    cin >> n >> k;

    int cnt = 0;
    int64_t i;
    for (i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (cnt == k) {
                cout << i << '\n';
                return 0;
            }
        }
    }
    i--;
    for (; i > 0; --i) {
        if (i * i != n && n % i == 0) {
            cnt++;
            if (cnt == k) {
                cout << n / i << '\n';
                return 0;
            }
        }
    }
    cout << "-1\n";
}