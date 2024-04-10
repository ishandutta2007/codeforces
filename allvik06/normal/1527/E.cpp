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

struct SegTree {
    int n;
    vector <int> t, p;

    SegTree(int n) : n(n) {
        t.resize(4 * n);
        p.resize(4 * n);
    }

    inline void push(int v) {
        t[2 * v] += p[v];
        t[2 * v + 1] += p[v];
        p[2 * v] += p[v];
        p[2 * v + 1] += p[v];
        p[v] = 0;
    }

    void update(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            t[v] += x;
            p[v] += x;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B, x);
        update(2 * v + 1, m + 1, r, A, B, x);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int get_min(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return INF;
        if (A <= l && r <= B) return t[v];
        push(v);
        int m = (l + r) / 2;
        return min(get_min(2 * v, l, m, A, B), get_min(2 * v + 1, m + 1, r, A, B));
    }
};

int n;
vector <int> a, prv, dp;

void recalc_dp() {
    SegTree t(n);
    for (int i = 0; i < n; ++i) {
        if (prv[i] != -1) t.update(1, 0, n - 1, 0, prv[i], i - prv[i]);
        t.update(1, 0, n - 1, i + 1, i + 1, dp[i]);
        dp[i] = t.get_min(1, 0, n - 1, 0, i);
    }
}

void solve1() {
    int k;
    cin >> n >> k;
    a.resize(n);
    prv.resize(n, -1);
    vector <int> cur(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        prv[i] = cur[a[i]];
        cur[a[i]] = i;
    }
    dp.resize(n);
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (prv[i] != -1) dp[i] += i - prv[i];
    }
    for (int i = 1; i < k; ++i) recalc_dp();
    cout << dp[n - 1] << "\n";
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