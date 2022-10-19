#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;
#define ll long long
int mod;

inline int sum(int a, int b) {
    if (a + b >= mod) return a + b - mod;
    return a + b;
}

inline int delta(int a, int b) {
    if (a >= b) return a - b;
    return a - b + mod;
}

inline int mult(int a, int b) {
    return (ll)a * (ll)b % mod;
}

vector <pair <int, int>> all;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, q;
    cin >> n >> q >> mod;
    vector <int> a(n + 2);
    for (int i = 2; i < n + 2; ++i) cin >> a[i];
    for (int i = 2; i < n + 2; ++i) {
        int x;
        cin >> x;
        a[i] = delta(a[i], x);
    }
    all.resize(n + 2);
    all[0].first = 1;
    all[1].second = 1;
    for (int i = 2; i <= n + 1; ++i) {
        all[i].first = sum(all[i - 1].first, all[i - 2].first);
        all[i].second = sum(all[i - 1].second, all[i - 2].second);
    }
    vector <int> b(n);
    for (int i = 0; i < n; ++i) b[i] = delta(delta(a[i + 2], a[i + 1]), a[i]);
    int cnt_bad = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) ++cnt_bad;
    }
    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r; --l; --r;
        vector <int> poses = {l, r + 1, r + 2};
        for (int i : poses) {
            if (i >= n) continue;
            if (b[i] > 0) --cnt_bad;
        }
        int x = 1;
        if (c == 'B') x = mod - 1;
        b[l] = sum(b[l], x);
        int prev_last, last;
        if (l == r) prev_last = 0;
        else prev_last = sum(mult(x, all[r - l - 1].first), mult(x, all[r - l - 1].second));
        last = sum(mult(x, all[r - l].first), mult(x, all[r - l].second));
        if (r < n - 1) {
            b[r + 1] = delta(delta(b[r + 1], prev_last), last);
            if (r < n - 2) {
                b[r + 2] = delta(b[r + 2], last);
            }
        }
        for (int i : poses) {
            if (i >= n) continue;
            if (b[i] > 0) ++cnt_bad;
        }
        if (cnt_bad == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

 */