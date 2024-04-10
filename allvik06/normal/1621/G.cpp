#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

struct Fenwick {
    int n;
    vector <int> f;

    inline Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add(int i, int x) {
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

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> all = a;
        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());
        for (int& i : a) i = lower_bound(all.begin(), all.end(), i) - all.begin();
        int m = (int)all.size();
        vector <int> dp1(n);
        Fenwick t1(m);
        for (int i = 0; i < n; ++i) {
            dp1[i] = (t1.get_pref(a[i] - 1) + 1) % mod;
            t1.add(a[i], dp1[i]);
        }
        vector <vector <int>> flex(m);
        for (int i = 0; i < n; ++i) flex[a[i]].push_back(i);
        int cur_max = -1;
        vector <int> bl(n, -1);
        for (int i = m - 1; i >= 0; --i) {
            for (int j : flex[i]) {
                if (cur_max > j) bl[j] = cur_max;
            }
            for (int j : flex[i]) {
                cur_max = max(cur_max, j);
            }
        }
        vector <int> dp2(n), dp3(n);
        Fenwick t2(m), t3(m);
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = (1 + t2.get_seg(a[i] + 1, m - 1)) % mod;
            t2.add(a[i], dp2[i]);
            if (bl[i] == -1) continue;
            dp3[i] = (1 + t3.get_seg(a[i] + 1, a[bl[i]] - 1)) % mod;
            t3.add(a[i], dp3[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (bl[i] != -1) {
                int cnt_good = (dp2[i] - dp3[i] + mod) % mod;
                ans = (ans + cnt_good * dp1[i]) % mod;
            }
        }
        cout << ans << "\n";
    }
}

/*

 */