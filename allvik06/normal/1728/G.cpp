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
const int mod = 998244353;

inline int power(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        n >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void solve1() {
    int d, n, m;
    cin >> d >> n >> m;
    vector <int> l(n), p(m);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < m; ++i) cin >> p[i];
    sort(l.begin(), l.end());
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    vector <vector <int>> val(m, vector <int> (n));
    for (int i = 0; i < m; ++i) {
        int f = lower_bound(l.begin(), l.end(), p[i]) - l.begin();
        if (f < n && l[f] == p[i]) {
            continue;
        }
        int cur_ans = 1;
        for (int j = f; j < n; ++j) {
            cur_ans = (cur_ans * (l[j] - p[i])) % mod;
            val[i][j] = cur_ans;
        }
        cur_ans = 1;
        for (int j = f - 1; j >= 0; --j) {
            cur_ans = (cur_ans * (p[i] - l[j])) % mod;
            val[i][j] = cur_ans;
        }
    }
    vector <vector <int>> val2(m, vector <int> (m));
    vector <int> val_left(m), val_right(m);
    for (int mask = 1; mask < (1 << m); ++mask) {
        int val_mask = 1;
        vector<int> all;
        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) all.push_back(i);
        }
        int ln = (int) all.size();
        if (l[0] <= p[all.front()]) val_mask = (val_mask * val[all.front()][0]) % mod;
        if (l.back() >= p[all.back()]) val_mask = (val_mask * val[all.back()].back()) % mod;
        for (int i = 0; i < ln - 1; ++i) {
            int x = (p[all[i]] + p[all[i + 1]]) / 2;
            int f = upper_bound(l.begin(), l.end(), x) - l.begin();
            if (f && l[f - 1] >= p[all[i]]) val_mask = (val_mask * val[all[i]][f - 1]) % mod;
            if (f < n && l[f] <= p[all[i + 1]]) val_mask = (val_mask * val[all[i + 1]][f]) % mod;
        }
        if (ln & 1) val_mask = (mod - val_mask) % mod;
        val_right[all.front()] = (val_right[all.front()] + val_mask) % mod;
        val_left[all.back()] = (val_left[all.back()] + val_mask) % mod;
        for (int i = 0; i < ln - 1; ++i) {
            val2[all[i]][all[i + 1]] = (val2[all[i]][all[i + 1]] + val_mask) % mod;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int ans = power(d + 1, n + 1);
        for (int i = 0; i < m; ++i) {
            if (x >= p[i]) ans = (ans + val_left[i] * (x - p[i])) % mod;
            if (x <= p[i]) ans = (ans + val_right[i] * (p[i] - x)) % mod;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if (p[i] <= x && x <= p[j]) ans = (ans + val2[i][j] * min(x - p[i], p[j] - x)) % mod;
            }
        }
        cout << ans << "\n";
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
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */