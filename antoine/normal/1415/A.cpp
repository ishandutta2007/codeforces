#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    return max(
            max(x - 1 + y - 1, x - 1 + m - y),
            max(n - x + m - y, n - x + y - 1)
            );

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}