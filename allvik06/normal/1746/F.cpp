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
const int CNT_VAL = 30;

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

inline void solve() {
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> all_q;
    vector <int> all = a;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int j, x;
            cin >> j >> x;
            all.push_back(x);
            all_q.push_back({j - 1, x});
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            all_q.push_back({l - 1, r - 1, k});
        }
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int ln = (int)all.size();
    vector <vector <int>> ran(ln);
    for (int i = 0; i < ln; ++i) {
        for (int j = 0; j < CNT_VAL; ++j) {
            ran[i].push_back(rnd() % (int)1e9);
        }
    }
    vector <Fenwick> f(CNT_VAL, Fenwick(n));
    for (int i = 0; i < n; ++i) {
        int num = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
        for (int j = 0; j < CNT_VAL; ++j) {
            f[j].add(i, ran[num][j]);
        }
    }
    for (auto& i : all_q) {
        if ((int)i.size() == 2) {
            int num = i[0];
            int x = i[1];
            int val_num = lower_bound(all.begin(), all.end(), a[num]) - all.begin();
            int new_val = lower_bound(all.begin(), all.end(), x) - all.begin();
            for (int j = 0; j < CNT_VAL; ++j) {
                f[j].add(num, ran[new_val][j] - ran[val_num][j]);
            }
            a[num] = x;
        } else {
            int l = i[0], r = i[1], k = i[2];
            bool ok = true;
            for (int j = 0; j < CNT_VAL; ++j) {
                if (f[j].get_seg(l, r) % k != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
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
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */