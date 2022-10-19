#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
const int MAXN = 2e5 + 10;

struct Fenwick {
    int n;
    vector <int> f;

    Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add(int i, int x) {
        for (++i; i <= n; i += (i & (-i))) f[i] += x;
    }

    inline int get_pref(int i) {
        int ans = 0;
        for (++i; i > 0; i -= (i & (-i))) ans += f[i];
        return ans;
    }

    inline int get_seg(int l, int r) {
        return get_pref(r) - get_pref(l - 1);
    }
};

void solve1() {
    int q;
    cin >> q;
    vector <vector <pair <int, int>>> all_q(MAXN);
    vector <vector <int>> all_d(MAXN), all_d2(MAXN);
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 2 * i; j < MAXN; j += i) {
            all_d[j].push_back(i);
            if ((j / i) % 2 == 1 && i * 2 < j) all_d2[j].push_back(i * 2);
        }
    }
    Fenwick f(MAXN);

    auto get_seg_cnt = [&](vector <int>& a, int l, int r) -> int {
        if (l > r) return 0;
        return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    };

    auto relax_val = [&](int i, int val) {
        for (int k = i * 2; k < MAXN; k += i) {
            f.add(k, get_seg_cnt(all_d[k], i + 1, k - 1) * val);
            f.add(k, get_seg_cnt(all_d2[k], max(k - i + 1, i + 1), k - 1) * val);
        }
        if (i & 1) return;
        int x = i / 2;
        for (int k = x * 3; k < MAXN; k += x) {
            if ((k / x) % 2 == 0) continue;
            f.add(k, get_seg_cnt(all_d[k], max(k - i + 1, i + 1), k - 1) * val);
            f.add(k, get_seg_cnt(all_d2[k], max(k - i + 1, i + 1), k - 1) * val);
        }
    };

    for (int i = 1; i < MAXN; ++i) relax_val(i, 1);
    vector <int> ans(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        ans[i] = len * (len - 1) * (len - 2) / 6;
        all_q[l].emplace_back(r, i);
    }
    for (int l = 1; l < MAXN; ++l) {
        for (auto i : all_q[l]) {
            ans[i.second] -= f.get_seg(l, i.first);
        }
        relax_val(l, -1);
    }
    for (int i : ans) cout << i << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */