#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
const int mod = 1e9 + 7;
#define int long long

struct Fenwick {
    int n;
    vector <int> f;

    Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void update(int i, int x) {
        x = (x % mod + mod) % mod;
        for (++i; i <= n; i += (i & (-i))) f[i] = (f[i] + x) % mod;
    }

    inline int get_pref(int i) {
        int ans = 0;
        for (++i; i > 0; i -= (i & (-i))) ans = (ans + f[i]) % mod;
        return ans;
    }

    inline int get_seg(int l, int r) {
        return (get_pref(r) - get_pref(l - 1) + mod) % mod;
    }
};

vector <int> solve(int n, int q, const vector <int>& a, const vector <int>& b, const vector <array <int, 3>>& query) {
    vector <int> all = b;
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    vector <vector <int>> all_m(n), all_p(n);
    for (int i = 0; i < q; ++i) {
        if (query[i][0]) all_m[query[i][0] - 1].push_back(i);
        all_p[query[i][1]].push_back(i);
    }
    int l = (int)all.size();
    Fenwick fa(l), fb(l);
    vector <int> ans(q);
    for (int i = 0; i < n; ++i) {
        int bb = b[i] % mod;
        fa.update(lower_bound(all.begin(), all.end(), b[i]) - all.begin(), a[i]);
        fb.update(lower_bound(all.begin(), all.end(), b[i]) - all.begin(), a[i] * bb);
        for (int j : all_m[i]) {
            int f1 = lower_bound(all.begin(), all.end(), -query[j][2]) - all.begin();
            ans[j] -= fb.get_seg(f1, l - 1) + fa.get_seg(f1, l - 1) * (query[j][2] % mod);
            ans[j] += fb.get_seg(0, f1 - 1) + fa.get_seg(0, f1 - 1) * (query[j][2] % mod);
        }
        for (int j : all_p[i]) {
            int f1 = lower_bound(all.begin(), all.end(), -query[j][2]) - all.begin();
            ans[j] += fb.get_seg(f1, l - 1) + fa.get_seg(f1, l - 1) * (query[j][2] % mod);
            ans[j] -= fb.get_seg(0, f1 - 1) + fa.get_seg(0, f1 - 1) * (query[j][2] % mod);
        }
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector <array <int, 3>> query(q);
    for (int i = 0; i < q; ++i) {
        cin >> query[i][0] >> query[i][1]; --query[i][0]; --query[i][1];
    }
    vector <int> ans(q);
    {
        vector <int> ta = a, tb(n);
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) tb[i + 1] = tb[i] + b[i];
            if (b[i] > 0) ta[i] = 0;
        }
        for (int i = 0; i < q; ++i) {
            query[i][2] = -tb[query[i][0]];
        }
        auto res = solve(n, q, ta, tb, query);
        for (int i = 0; i < q; ++i) ans[i] = (ans[i] + res[i]) % mod;
    }
    {
        vector <int> ta = a, tb(n, b[0]);
        for (int i = 0; i < n; ++i) {
            if (i) tb[i] = tb[i - 1] + b[i];
            if (b[i] > 0) ta[i] = 0;
        }
        auto res = solve(n, q, ta, tb, query);
        for (int i = 0; i < q; ++i) ans[i] = (ans[i] - res[i]) % mod;
    }
    {
        vector <int> ta = a, tb(n);
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) tb[i + 1] = tb[i] - b[i];
            if (b[i] < 0) ta[i] = 0;
        }
        for (int i = 0; i < q; ++i) {
            query[i][2] = -tb[query[i][0]];
        }
        auto res = solve(n, q, ta, tb, query);
        for (int i = 0; i < q; ++i) ans[i] = (ans[i] + res[i]) % mod;
    }
    {
        vector <int> ta = a, tb(n, -b[0]);
        for (int i = 0; i < n; ++i) {
            if (i) tb[i] = tb[i - 1] - b[i];
            if (b[i] < 0) ta[i] = 0;
        }
        auto res = solve(n, q, ta, tb, query);
        for (int i = 0; i < q; ++i) ans[i] = (ans[i] - res[i]) % mod;
    }
    for (int i : ans) cout << (i + mod) % mod << "\n";
}