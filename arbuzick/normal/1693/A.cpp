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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int nw = 0;
    bool ch = true;
    int pos = n;
    for (int i = 0; i + 1 < n; ++i) {
        if (nw > a[i]) {
            ch = false;
            break;
        } else if (nw == a[i]) {
            pos = i;
            nw = 0;
            break;
        }
        nw = -(a[i] - nw);
    }
    for (int j = pos + 1; j < n; ++j) {
        if (a[j] != 0) {
            ch = false;
            break;
        }
    }
    if (!ch || nw != a[n - 1]) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
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