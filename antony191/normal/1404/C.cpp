#include <iostream>
#include <vector>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

//mt19937 rnd(time(nullptr));

struct fenwick {
    vector<int> f;
    int n;
    fenwick(int _n) {
        n = _n;
        f.assign(n, 0);
    }
    void upd(int x, int d) {
        for (; x < n; x = x | (x + 1))
            f[x] += d;
    }
    int sum(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans += f[r];
        return ans;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n, n + 1);
    forn(i, n) {
        cin >> a[i];
        a[i]--;
    }
    fenwick f(n + 1);
    forn(i, n) {
        if (a[i] > i) continue;
        int add = i - a[i];
        int l = 0, r = n + 1;
        while(r - l > 1) {
            int m = (l + r) >> 1;
            if (f.sum(m) >= add) r = m;
            else l = m;
        }
        if (r <= n) {
            uax(r, n - i);
            b[i] = r;
            f.upd(r, 1);
        }
    }
    vector<pair<pair<int, int>, int>> ask(q);
    forn(i, q) {
        cin >> ask[i].x.y >> ask[i].x.x;
        ask[i].y = i;
    }
    sort(rall(ask));
    vector<int> ans(q);
    fenwick t(n + 1);
    int r = 0;
    forn(i, q) {
        while(r + ask[i].x.x < n) {
            if (b[r] <= n) t.upd(b[r], 1);
            r++;
        }
        ans[ask[i].y] = t.sum(n - ask[i].x.y);
    }
    forn(i, q) cout << ans[i] << el;
    return 0;
}