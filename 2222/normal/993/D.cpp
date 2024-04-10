#include <bits/stdc++.h>

using namespace std;

#define sz(a)           int((a).size())
#define all(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for (int i = 0, _n(b); i < _n; ++i)
#define REP(i,n)        FOR(i, 0, n)
#define X               first
#define Y               second

int n;

pair<int64_t, int64_t> c[55];

bool relax(int64_t& x, int64_t y) { return y < x ? (x = y, true) : false; }

bool solve() {
    vector<int64_t> f(n + 1, -1ull/2);
    f[0] = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        for (; j < n && c[i].Y == c[j].Y; ++j);
        sort(c + i, c + j);
        int64_t s[55];
        const int m = j - i;
        s[0] = 0;
        REP (k, m) s[k + 1] = s[k] + c[i + k].X;
        vector<int64_t> g(n + 1, -1ull/2);
        for (int k = 0; k <= n; ++k) {
            if (f[k] == -1ull/2) continue;
            for (int t = 0; t <= k && t <= j - i && k + m - 2 * t <= n; ++t) {
                relax(g[k + m - 2 * t], f[k] + s[m - t]);
            }
        }
        swap(f, g);
    }
    return *min_element(all(f)) <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin >> n;
    vector<int64_t> a(n), b(n);
    REP (i, n) { cin >> a[i]; a[i] *= 1000; }
    REP (i, n) cin >> b[i];
    REP (j, n) REP (i, j) if (a[i] < a[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
    }
    int64_t lo = -1, hi = 1e12;
    for (; lo + 1 < hi; ) {
        int64_t mid = lo + (hi - lo) / 2;
        REP (i, n) c[i] = {a[i] - mid * b[i], a[i]};
        (solve() ? hi : lo) = mid;
    }
    cout << hi << endl;
    return 0;
}