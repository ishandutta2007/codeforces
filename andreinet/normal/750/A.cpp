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

    int a = 60 * 4;

    int n, k;
    cin >> n >> k;

    int ans = 0;
    a -= k;
    for (int i = 1; i <= n; ++i) {
        if (a >= 5 * i) {
            ans = i;
            a -= 5 * i;
        } else {
            break;
        }
    }
    cout << ans << '\n';
}