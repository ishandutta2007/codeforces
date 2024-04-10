#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> d;
    int x = n;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            d.push_back(n / i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        d.push_back(n / x);
    }
    sort(d.begin(), d.end());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<long long>> ans(d.size());
    multiset<long long> ms;
    for (int i = 0; i < (int)d.size(); ++i) {
        ans[i].assign(d[i], 0);
        for (int j = 0; j < n; ++j) {
            ans[i][j % d[i]] += a[j];
        }
        for (int j = 0; j < d[i]; ++j) {
            ans[i][j] *= d[i];
            ms.insert(ans[i][j]);
        }
    }
    cout << *ms.rbegin() << '\n';
    while (q--) {
        int ind, x;
        cin >> ind >> x;
        ind--;
        for (int i = 0; i < (int)d.size(); ++i) {
            ms.erase(ms.find(ans[i][ind % d[i]]));
            ans[i][ind % d[i]] -= a[ind] * 1LL * d[i];
            ans[i][ind % d[i]] += x * 1LL * d[i];
            ms.insert(ans[i][ind % d[i]]);
        }
        a[ind] = x;
        cout << *ms.rbegin() << '\n';
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