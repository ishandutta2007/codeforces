#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> bit(n + 1, 0);
    auto update = [&](int k, int val) {
        for (int i = k; i <= n; i += (i & (-i))) {
            bit[i] = max(bit[i], val);
        }
    };
    auto get = [&](int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res = max(res, bit[i]);
        }
        return res;
    };
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) pos[a[i]].push_back(i + 1);
    sort(pos.begin(), pos.end(), [&](const vector<int> &x, const vector<int> &y) {
        if (y.empty()) return false;
        if (x.empty()) return true;
        return x.back() < y.back();
    });
    int ans = 0;
    for (const vector<int> &e : pos) {
        if (e.empty()) continue;
        for (int i = 0; i < e.size(); i++) {
            ans = max(ans, get(e[i] - 1) + (int) e.size() - i);
        }
        update(e.back(), get(e[0] - 1) + e.size());
    }
    ans = max(ans, get(n));
    cout << n - ans << '\n';
    return 0;
}