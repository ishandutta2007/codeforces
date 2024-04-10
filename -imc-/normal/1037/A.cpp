#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

#define int li

void solve(bool);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

    return 0;
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 0; ; ++i) {
        if (n < (1 << i)) {
            break;
        }
        n -= 1 << i;
        ++cnt;
    }

    if (n > 0) {
        ++cnt;
    }

    cout << cnt << endl;
}