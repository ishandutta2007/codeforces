#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vl;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }

template <class T> struct SegmentTree {
    const T ID = 0;

    T comb(T a, T b) {
        return max(a, b);
    }

    int n;
    std::vector<T> seg;

    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    void add(int p, T val) {
        seg[p += n] += val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        if (l > r) return 0;
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

void solve_case() {
    int n; cin >> n;

    vi a(n);
    f0r(i, n) cin >> a[i], a[i]--;
    vector<vi> loc(n);
    f0r(i, n) loc[a[i]].pb(i);
    int cnt = 0;
    vpi ival;
    f0r(i, n) {
        if (sz(loc[i]) == 0) continue;
        int l = loc[i][0];
        int r = loc[i].back();
        ival.eb(l, r);
    }
    int i1 = 0;
    int i2 = 0;
    int mx = 0;
    while (i1 != sz(ival)) {
        while (i2 != sz(ival)-1 && ival[i2].s < ival[i2+1].f) i2++;
        ckmax(mx, i2-i1+1);
        i1 = ++ i2;
    }
    int ans = sz(ival)-mx;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}