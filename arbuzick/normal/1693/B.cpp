#include <bits/stdc++.h>
#define int long long

using namespace std;

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    vector<int> add(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (add[i] < l[i]) {
            ans++;
            add[i] = r[i];
        } else {
            add[i] = min(add[i], r[i]);
        }
        if (i != 0) {
            add[p[i]] += add[i];
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}