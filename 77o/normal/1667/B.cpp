#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

mt19937 rng(123);

const int N = 5e5 + 5;
int dp1[N * 4], dp2[N * 4];

void update(int t[], int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = max(t[v], new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t, v*2, tl, tm, pos, new_val);
        else
            update(t, v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int t[], int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1e9;
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(query(t, v*2, tl, tm, l, min(r, tm)), 
               query(t, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    map<ll, int> kek;
    {
        auto c = p;
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());
        for (int i = 0; i < c.size(); i++)
            kek[c[i]] = i;
    }
    fill(dp1, dp1 + (n + 1) * 4, -1e9);
    fill(dp2, dp2 + (n + 1) * 4, -1e9);
    vector<ll> aaaa(n + 1, -1e9);
    update(dp1, 1, 0, n + 1, kek[0], 0);
    update(dp2, 1, 0, n + 1, kek[0], 0);
    aaaa[kek[0]] = 0;
    ll last = 0;
    for (int i = 1; i <= n; i++) {
        int pos = kek[p[i]];
        ll val = max(query(dp1, 1, 0, n + 1, 0, pos - 1) + i, query(dp2, 1, 0, n + 1, pos + 1, n + 1) - i);
        val = max(val, aaaa[pos]);
        update(dp1, 1, 0, n + 1, pos, val - i);
        update(dp2, 1, 0, n + 1, pos, val + i);
        last = val;
        aaaa[pos] = val;
    }
    cout << last << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}