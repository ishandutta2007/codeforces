

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

const ll INF = 1e18;

struct LazySeg {
    vl st;
    vl lz;
    int sz;

    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        st.assign(2 * sz, INF);
        lz.assign(2 * sz, INF);
    }

    void push(int ind, int L, int R) {
        ckmin(st[ind], lz[ind]);
        if (L != R) {
            ckmin(lz[2 * ind], lz[ind]);
            ckmin(lz[2 * ind + 1], lz[ind]);
        }
        lz[ind] = INF;
    }

    void pull(int ind) {
        st[ind] = min(st[2 * ind], st[2 * ind + 1]);
    }

    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (R < lo || hi < L) return;
        if (lo <= L && R <= hi) {
            lz[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) >> 1;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }

    ll query(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (R < lo || hi < L) return INF;
        if (lo <= L && R <= hi) return st[ind];
        int M = (L + R) >> 1;
        return min(query(lo, hi, 2 * ind, L, M), query(lo, hi, 2 * ind + 1, M + 1, R));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vl a(n), c(n);
    f0r(i, n) cin >> a[i] >> c[i];
    vi v(n);
    iota(all(v), 0);
    sort(all(v), [&](int x, int y) {
        return a[x] < a[y];
    });
    ll ans = 0;
    f0r(i, n) ans += c[i];
    LazySeg flat, add;
    flat.init(n);
    add.init(n);
    flat.upd(0, 0, 0);
    f0r(i, n) {
        ll val = min(flat.query(i, i), add.query(i, i) + a[v[i]]);
        int lo = i;
        int hi = n - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (a[v[mid]] - a[v[i]] >= c[v[i]]) hi = mid;
            else lo = mid + 1;
        }
        int loc = -1;
        if (a[v[lo]] - a[v[i]] >= c[v[i]]) loc = lo;
        else if (a[v[hi]] - a[v[i]] >= c[v[i]]) loc = hi;
        if (loc == -1) {
            flat.upd(i + 1, n - 1, val);
        } else {
            flat.upd(i + 1, loc - 1, val);
            add.upd(loc, n - 1, val - c[v[i]] - a[v[i]]);
        }
        if (i == n - 1) ans += val;
    }
    cout << ans << '\n';
    return 0;
}