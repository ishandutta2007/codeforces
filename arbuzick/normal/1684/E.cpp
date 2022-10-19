#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> count;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        count[a[i]]++;
    }
    vector<pair<int, int>> vals;
    for (auto [val, cnt] : count) {
        vals.push_back({cnt, val});
    }
    sort(vals.begin(), vals.end());
    map<int, int> pos;
    for (int i = 0; i < (int) vals.size(); ++i) {
        pos[vals[i].second] = i;
    }
    struct fenwik_tree {
        int sz;
        vector<long long> f;
        fenwik_tree(int _sz) {
            sz = _sz + 1;
            f.assign(sz, 0);
        }
        void add(int p, int val) {
            p++;
            for (int i = p; i < sz; i += i & -i) {
                f[i] += val;
            }
        }
        long long get(int p) {
            long long sum = 0;
            for (int i = p; i > 0; i -= i & -i) {
                sum += f[i];
            }
            return sum;
        }
    };
    fenwik_tree f(vals.size()), f2(vals.size());
    for (int i = 0; i < (int) vals.size(); ++i) {
        f.add(i, vals[i].first);
    }
    int ans = count.size();
    auto count_ch = [&](int k) -> int {
        int l = 0, r = vals.size() + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (f.get(m) <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        return l - f2.get(l);
    };
    ans -= min((int) vals.size() - 1, count_ch(k));
    int add = 0;
    for (int mex = 1; mex <= n; ++mex) {
        if (count[mex - 1] == 0) {
            add++;
        } else {
            f.add(pos[mex - 1], -count[mex - 1]);
            f2.add(pos[mex - 1], 1);
        }
        if (add > k) {
            break;
        }
        ans = min(ans, (int) vals.size() - count_ch(k) + add - mex);
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