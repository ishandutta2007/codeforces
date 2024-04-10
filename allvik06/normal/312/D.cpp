#pragma GCC optimize("Ofast,unroll-loops")
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
const int INF = 1e15;
vector <int> psum;

struct line {
    int k = 0, b = INF;

    line(int k, int b) : k(k), b(b)  {}

    line() {}
};

inline int get_val(const line& a, int x) {
    return a.k * x + a.b;
}

struct LiChao {
    int n;
    vector <int> c;
    vector <line> t;

    LiChao(int n, const vector <int>& _c) : n(n) {
        t.resize(4 * n);
        c = _c;
    }

    void update(int v, int l, int r, line a) {
        if (l > r) return;
        int m = (l + r) / 2;
        if (get_val(a, c[m]) < get_val(t[v], c[m])) {
            swap(t[v], a);
        }
        if (get_val(a, c[l]) < get_val(t[v], c[l])) {
            update(2 * v, l, m - 1, a);
        } else {
            update(2 * v + 1, m + 1, r, a);
        }
    }

    int get_point(int v, int l, int r, int i) {
        if (l > i || i > r) return INF;
        int m = (l + r) / 2;
        return min({get_point(2 * v, l, m - 1, i), get_point(2 * v + 1, m + 1, r, i), get_val(t[v], c[i])});
    }
};

inline void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector <int> d(n);
    for (int i = 1; i < n; ++i) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    vector <int> all(m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x, t;
        cin >> x >> t;
        int tt = t - d[x - 1];
      //  if (t - d[x - 1] < 0) ans += abs(t - d[x - 1]);
        all[i] = tt;
    }
    sort(all.begin(), all.end());
    psum.resize(m + 1);
    for (int i = 0; i < m; ++i) psum[i + 1] = psum[i] + all[i];
    vector <int> dp1(m + 1, INF), dp2(m + 1, INF);
    dp1[0] = 0;
    for (int i = 1; i <= p; ++i) {
        LiChao t(m, all);
        dp2[0] = 0;
        t.update(1, 0, m - 1, line(0, 0));
        for (int j = 0; j < m; ++j) {
            int val = t.get_point(1, 0, m - 1, j) + all[j] * (j + 1) - psum[j + 1];
            t.update(1, 0, m - 1, line(-(j + 1), dp1[j + 1] + psum[j + 1]));
            dp2[j + 1] = val;
        }
        dp1.swap(dp2);
    }
    cout << dp1.back() + ans;
}

void solve2() {
    int n, m, p;
    cin >> n >> m >> p;
    vector <int> d(n);
    for (int i = 1; i < n; ++i) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    vector <int> all(m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x, t;
        cin >> x >> t;
        int tt = t - d[x - 1];
      //  if (t - d[x - 1] < 0) ans += abs(t - d[x - 1]);
        all[i] = tt;
    }
    sort(all.begin(), all.end());
    psum.resize(m + 1);
    for (int i = 0; i < m; ++i) psum[i + 1] = psum[i] + all[i];
    vector <int> dp1(m + 1, INF), dp2(m + 1, INF);
    dp1[0] = 0;
    for (int _ = 1; _ <= p; ++_) {
        dp2.assign(m + 1, INF);
        dp2[0] = 0;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k <= j; ++k) {
                int val = dp1[k] + all[j] * (j - k + 1) - (psum[j + 1] - psum[k]);
                dp2[j + 1] = min(dp2[j + 1], val);
            }
        }
        dp1.swap(dp2);
    }
    cout << dp1.back() + ans;
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
    }
}

/*

 */