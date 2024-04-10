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
    string a, b;
    cin >> n >> a >> b;

    auto ans = [&](string& cur) {
        int n = cur.length();

        int t = 0;

        for (int i = 0; i < n;) {
            if (i + 1 < n && cur[i] != cur[i + 1]) {
                i += 2;
                ++t;
            } else {
                ++i;
                ++t;
            }
        }

        return t;
    };

    li answer = 0;

    string cur = "";
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            cur += a[i];
        } else {
            answer += ans(cur);
            cur = "";
        }
    }
    answer += ans(cur);

    cout << answer << endl;
}