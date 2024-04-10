#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long
const int INF = 1e9;

struct SegTree {
    int n;
    vector <int> t;

    SegTree(int n) : n(n) {
        t.resize(4 * n, INF);
    }

    void update(int v, int l, int r, int i, int x) {
        if (l > i || i > r) return;
        if (l == r) {
            t[v] = x;
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x);
        update(2 * v + 1, m + 1, r, i, x);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int get_min(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return INF;
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return min(get_min(2 * v, l, m, A, B), get_min(2 * v + 1, m + 1, r, A, B));
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
        vector <int> dp(n, INF);
        vector <int> st_max, st_min;
        SegTree mx(n), mn(n);
        st_max.push_back(n - 1);
        st_min.push_back(n - 1);
        mx.update(1, 0, n - 1, n - 1, 0);
        mn.update(1, 0, n - 1, n - 1, 0);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            while (!st_max.empty() && a[i] > a[st_max.back()]) {
                mx.update(1, 0, n - 1, st_max.back(), INF);
                st_max.pop_back();
            }
            while (!st_min.empty() && a[i] < a[st_min.back()]) {
                mn.update(1, 0, n - 1, st_min.back(), INF);
                st_min.pop_back();
            }
            if (st_max.empty()) dp[i] = mn.get_min(1, 0, n - 1, i, n - 1) + 1;
            else dp[i] = mn.get_min(1, 0, n - 1, i, st_max.back() - 1) + 1;
            if (st_min.empty()) dp[i] = min(mx.get_min(1, 0, n - 1, i, n - 1) + 1, dp[i]);
            else dp[i] = min(mx.get_min(1, 0, n - 1, i, st_min.back() - 1) + 1, dp[i]);
            st_max.push_back(i);
            st_min.push_back(i);
            mx.update(1, 0, n - 1, i, dp[i]);
            mn.update(1, 0, n - 1, i, dp[i]);
        }
        cout << dp[0] << "\n";
    }
}

/*

 */