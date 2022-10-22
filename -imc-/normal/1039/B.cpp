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

    //while (true) solve(false);

    return 0;
}

void solve(bool __attribute__((unused)) read) {
    int n, k;
    cin >> n >> k;

    srand(218332 + n + k);

    int low = 1, high = n;

    while (true) {
        int m = (low + high) / 2;

        cout << low << " " << m << endl;
        string ans;
        cin >> ans;

        if (ans == "Yes") {
            if (low == m) {
                break;
            }

            high = m;
        } else {
            low = m + 1;
        }

        low = max<li>(1, low - k);
        high = min<li>(n, high + k);

        if (high - low + 1 <= 60) {
            int x = low + rand() % (high - low + 1);
            cout << x << " " << x << endl;
            string ans;
            cin >> ans;
            if (ans == "Yes") {
                return;
            }

            low = max<li>(1, low - k);
            high = min<li>(n, high + k);
        }
    }
}