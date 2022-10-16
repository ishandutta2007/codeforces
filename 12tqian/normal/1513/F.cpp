#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e9;

template <class T> struct SegmentTree {
    const T ID = -INF;

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

    void set_max(int p, T val) {
        ckmax(seg[p += n], val);
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vpi v(n);
    f0r(i, n) cin >> v[i].f;
    f0r(i, n) cin >> v[i].s;
    sort(all(v), [&](pi x, pi y) {
        if (x.f > x.s) swap(x.f, x.s);
        if (y.f > y.s) swap(y.f, y.s);
        return x < y;
    });
    vi vals;
    f0r(i, n) vals.pb(v[i].f), vals.pb(v[i].s);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    auto get_pos = [&](int x) -> int {
        return lower_bound(all(vals), x) - vals.begin();
    };

    int sub = 0;

    int sz = sz(vals);

    SegmentTree<int> seg1;
    seg1.init(sz);
    SegmentTree<int> seg2;
    seg2.init(sz);

    ll ans = 0;
    f0r(i, n) ans += abs(v[i].f - v[i].s);


    f0r(i, n) {
        int l = v[i].f;
        int r = v[i].s;
        if (l < r) {
            int lid = get_pos(l);
            int rid = get_pos(r);
            ckmax(sub, seg2.query(lid, rid) - l);
            if (seg2.query(rid, sz - 1) != -INF) {
                ckmax(sub, r - l);
            }
            seg1.set_max(rid, r);
        } else {
            swap(l, r);
            int lid = get_pos(l);
            int rid = get_pos(r);
            ckmax(sub, seg1.query(lid, rid) - l);
            if (seg1.query(rid, sz - 1) != -INF) {
                ckmax(sub, r - l);
            }
            seg2.set_max(rid, r);
        }
    }   

    ans -= sub * 2LL;

    cout << ans << '\n';

    return 0;
}