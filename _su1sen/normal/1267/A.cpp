/**
 *    author:  otera
**/
#include<bits/stdc++.h>
namespace otera {
    template <typename T>
    struct Compressor {
    public:
        static constexpr int absent = -1;

        Compressor() : _xs(std::vector<T>{}) {}

        Compressor(const std::vector<T>& vs) {
            add(vs);
            build();
        }

        void add(const std::vector<T>& vs) {
            std::copy(vs.begin(), vs.end(), std::back_inserter(_xs));
        }

        void add(const T& e) {
            _xs.emplace_back(e);
        }

        void build() {
            std::sort(_xs.begin(), _xs.end());
            _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());
        }

        int size() const {
            return _xs.size();
        }

        bool has_key(const T& e) const {
            return std::binary_search(_xs.begin(), _xs.end(), e);
        }

        std::vector<int> get(const std::vector<T>& vs) const {
            std::vector<int> res;
            std::transform(vs.begin(), vs.end(), std::back_inserter(res), [&](const T& e) {
                return get(e);
                });
            return res;
        }

        int get(const T& e, int default_value = absent) const {
            const int id = min_geq_index(e);
            return id != size() and _xs[id] == e ? id : default_value;
        }

        const T& operator[](int compressed_index) const {
            return _xs[compressed_index];
        }

        T min_gt(const T& e, const T& default_value) const {
            auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
            return it == _xs.end() ? default_value : *it;
        }
        T min_geq(const T& e, const T& default_value) const {
            auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
            return it == _xs.end() ? default_value : *it;
        }
        T max_lt(const T& e, const T& default_value) const {
            auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
            return it == _xs.begin() ? default_value : *std::prev(it);
        }
        T max_leq(const T& e, const T& default_value) const {
            auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
            return it == _xs.begin() ? default_value : *std::prev(it);
        }
        int min_gt_index(const T& e) const {
            return std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
        }
        int min_geq_index(const T& e) const {
            return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
        }
        int max_lt_index(const T& e) const {
            return int(std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin()) - 1;
        }
        int max_leq_index(const T& e) const {
            return int(std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin()) - 1;
        }
    private:
        std::vector<T> _xs;
    };
} // namespace oteraS

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace std;

#define int long long

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using int128_t = __int128_t;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define rev_repa(i, n) for(int i=n-1;i>=0;i--)
#define rev_repb(i, a, b) assert(a > b);for(int i=a;i>b;i--)
#define rev_rep(...) overload3(__VA_ARGS__, rev_repb, rev_repa)(__VA_ARGS__)
#define rev_rep1a(i, n) for(int i=n;i>=1;i--)
#define rev_rep1b(i, a, b) assert(a >= b);for(int i=a;i>=b;i--)
#define rev_rep1(...) overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(), c.rend()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
#define unless(A) if(!(A))
ll intpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) { ll ans = 1; while (b) { if (b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T, class U> using umap = unordered_map<T, U>;
template<class T> void scan(T& a) { cin >> a; }
template<class T> void scan(vector<T>& a) { for (auto&& i : a) scan(i); }
void in() {}
template <class Head, class... Tail> void in(Head& head, Tail&... tail) { scan(head); in(tail...); }
void print() { cout << ' '; }
template<class T> void print(const T& a) { cout << a; }
template<class T> void print(const vector<T>& a) { if (a.empty()) return; print(a[0]); for (auto i = a.begin(); ++i != a.end(); ) { cout << ' '; print(*i); } }
int out() { cout << '\n'; return 0; }
template<class T> int out(const T& t) { print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail) { print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_{};

const ll INF = 1LL << 60;

LP op(LP a, LP b) {
    return min(a, b);
}

LP e() {
    return LP{ INF, INF };
}

LP mapping(LP f, LP x) {
    return min(f, x);
}

LP comp(LP f, LP g) {
    return min(f, g);
}

LP _id() {
    return LP{ INF, INF };
}

void solve() {
    INT(n);
    vc<ll> a(n), b(n), t(n);
    vc<ll> xs;
    pqg<LP> pque;
    rep(i, n) {
        in(a[i], b[i], t[i]);
        // debug(i, a[i], t[i]);
        pque.push(LP{ a[i] + t[i], i });
        xs.eb(a[i]);
        xs.eb(b[i] - t[i] + 1);
    }
    xs.eb(INF); xs.eb(-INF);
    otera::Compressor<ll> cs(xs);
    int sz = si(cs);
    atcoder::lazy_segtree<LP, op, e, LP, mapping, comp, _id> seg(sz);
    rep(i, n) {
        int le = cs.get(a[i]);
        int ri = cs.get(b[i] - t[i] + 1);
        seg.apply(le, ri, LP{ t[i], i });
    }
    ll ans = 0;
    ll cur = -INF; //
    int id = -1;   // index
    while (1) {
        while (pque.size()) {
            auto [pos, j] = pque.top();
            if (cur <= pos - t[j]) break;
            pque.pop();
        }
        int pos = cs.max_leq_index(cur);
        assert(pos != -1);
        auto [len, i] = seg.prod(pos, pos + 1);
        if (len != INF) {
            id = i;
        } else {
            id = -1;
        }
        if (pque.size()) {
            auto [pos, i] = pque.top();
            if (id < 0 or pos <= cur + t[id]) {
                pque.pop();
                ++ans;
                cur = pos;
                id = i;
            } else {
                int q = (min(b[id], pos) - cur) / t[id];
                ans += q;
                cur += q * t[id];
            }
        } else if (id >= 0) {
            int q = (b[id] - cur) / t[id];
            ans += q;
            cur += q * t[id];
        } else {
            break;
        }
        if (id >= 0 and cur + t[id] > b[id]) {
            id = -1;
        }
    }
    out(ans);
}

signed main() {
    int testcase = 1;
    // in(testcase);
    while (testcase--) solve();
    return 0;
}