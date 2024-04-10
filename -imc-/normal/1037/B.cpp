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
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    li answer = 0;
    if (a[n / 2] > s) {
        for (int t = n / 2; t >= 0; --t) {
            answer += max<li>(a[t] - s, 0);
        }
    } else {
        for (int t = n / 2; t < n; ++t) {
            answer += max<li>(s - a[t], 0);
        }
    }
    cout << answer << endl;
}