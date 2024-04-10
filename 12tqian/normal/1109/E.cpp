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

namespace FactorBasic {

template <class T> std::vector<std::pair<T, int>> factor(T x) {
    std::vector<std::pair<T, int>> pri;
    for (T i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t++;
            pri.push_back({i, t});
        }
    }
    if (x > 1) pri.push_back({x, 1});
    return pri;
}

template <class T> T phi(T x) {
    for (auto& a : factor(x)) x -= x / a.first;
    return x;
}

template <class T> void tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res, int ind, T cur) {
    if (ind == (int)v.size()) res.push_back(cur);
    else {
        T mul = 1;
        for (int i = 0; i < v[ind].second + 1; i++) {
            tour(v, res, ind + 1, cur * mul);
            mul *= v[ind].first;
        }
    }
}

template <class T> std::vector<T> get_divisor(T x) {
    auto v = factor(x);
    std::vector<T> res; 
    tour(v, res, 0, (T) 1);
    sort(res.begin(), res.end());
    return res;
}

}

namespace BasicNumberTheory { 

// find solution to a * x + b * y = gcd(a, b)
// |a * x|, |b * y) <= lcm(a, b)
std::pair<long long, long long> euclid(long long a, long long b) {
    if (!b) 
        return {1, 0};
    std::pair<long long, long long> p = euclid(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

long long mod_inverse(long long a, long long b) {
    auto p = euclid(a, b);
    assert(p.first * a + p.second * b == 1); // gcd is 1
    return p.first + (p.first < 0) * b;
}

std::pair<long long, long long> CRT(std::pair<long long, long long> a, 
    std::pair<long long, long long> b) {
    if (a.second < b.second)
        std::swap(a, b);
    long long x, y;
    std::tie(x, y) = euclid(a.second, b.second);
    long long g = a.second * x + b.second * y;
    long long l = a.second / g * b.second;
    if ((b.first - a.first) % g)
        return {-1, -1}; // no solution
    x = (b.first - a.first) % b.second * x % b.second / g * a.second + a.first;
    return {x + (x < 0) * l, l};
}

long long cdiv(long long a, long long b) { // a / b rounded up
    return a / b + ((a ^ b) > 0 && a % b);
}

long long fdiv(long long a, long long b) { // a / b rounded down
    return a / b - ((a ^ b) < 0 && a % b);
}

// minimum x such that there is a y such that l <= a * x + b * y <= r
long long between(long long a, long long b, long long l, long long r) {
    a %= b;
    if (a == 0)
        return l == 0 ? 0 : -1;
    long long k = cdiv(l, a);
    if (a * k <= r)
        return k;
    long long x = between(b, a, a - r % a, a - l % a);
    return x == -1 ? x : cdiv(b * x + l, a);
}

// sum from i = 0 to i = n - 1 of floor(a * i + b / m), works for positive and negative m, a, b
long long floor_sum(long long n, long long m, long  long a, long long b) {
    if (m < 0) 
        a *= -1, b *= -1, m *= -1;
    long long na = a % m;
    if (na < 0) na += m;
    long long nb = b % m;
    if (nb < 0) nb += m;
    long long ans = 0;
    ans += n * (n - 1) / 2 * ((a - na) / m);
    ans += n * ((b - nb) / m);
    std::swap(a, na);
    std::swap(b, nb);
    long long y_max = (a * n + b) / m;
    long long x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

} // BasicNumberTheory

using namespace BasicNumberTheory;
using namespace FactorBasic; 

int mpow(ll b, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) {
            r *= b;
            r %= m;
        }
        b *= b;
        b %= m;
        e >>= 1;
    }
    return r;
}
int minv(int x, int m) { return mpow(x, m - 2, m); }

const int N = 1e5 + 5;
const int B = 1e9 + 7;

pi num[N];

struct LazySeg {
    int P; // prime modulo
    int E;
    int M;
    int PHI;
    vi pows;
    int sz;
    pi ID = {1, 0};
    vpi st;
    vpi lz;
    ll tmp;

    int ex(int e) {
        while (sz(pows) <= e) {
            pows.pb(1LL * pows.back() * P % M);
        }
        return pows[e];
    }

    int get(pi x) {
        tmp = 1LL * ex(x.s) * x.f;
        if (tmp >= B) tmp %= M;
        return tmp;
    }
    
    void pull(int ind) {
        st[ind].f = get(st[2 * ind]) + get(st[2 * ind + 1]);
        if (st[ind].f >= B) st[ind].f %= M;
    }

    void comb(pi& a, pi& b) {
        tmp = 1LL * a.f * b.f;
        if (tmp >= B) tmp %= M;
        a.f = tmp;
        a.s += b.s;
    }

    pi make(int x) {
        pi res; res.s = 0;
        while (x % P == 0) {
            res.s++;
            x /= P;
        }
        res.f = x;
        return res;
    }

    void init(vi& a, int P_, int E_) {
        P = P_;
        E = E_;
        M = 1;
        f0r(i, E) M *= P;
        PHI = M / P * (P - 1);
        f1r(i, 1, N) num[i] = make(i);
        pows = {1};
        int n = sz(a);
        sz = 1;
        while (sz < n) sz <<= 1;
        st.assign(2 * sz, {0, 0});
        lz.assign(2 * sz, ID);
        f0r(i, n) {
            st[i + sz] = num[a[i]];
        }
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }

    void push(int ind, int L, int R) {
        if (lz[ind] == ID) return;
        if (ind >= sz) 
            comb(st[ind], lz[ind]);
        else {
            tmp = 1LL * st[ind].f * get(lz[ind]);
            if (tmp >= B) tmp %= M;
            st[ind].f = tmp;
        }
        if (L != R) {
            comb(lz[2 * ind], lz[ind]);
            comb(lz[2 * ind + 1], lz[ind]);
        }
        lz[ind] = ID;
    }

    void point(int id, int x, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (id < L || R < id) return;
        if (L == R) {
            auto res = num[x];
            st[ind].s -= res.s;
            st[ind].f = 1LL * st[ind].f * mpow(res.f, PHI - 1, M) % M;
            return;
        }
        int M = (L + R) >> 1;
        point(id, x, 2 * ind , L, M);
        point(id, x, 2 * ind + 1, M + 1, R);
        pull(ind);
    }

    void range(int lo, int hi, int x, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lz[ind] = num[x];
            push(ind, L, R);
            return;
        }
        int M = (L + R) >> 1;
        range(lo, hi, x, 2 * ind, L, M);
        range(lo, hi, x, 2 * ind + 1, M + 1, R);
        pull(ind);
    }

    int query(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return 0;
        if (lo <= L && R <= hi) {
            return get(st[ind]);
        }
        int MD = (L + R) >> 1;
        int res = query(lo, hi, 2 * ind, L, MD);
        res += query(lo, hi, 2 * ind + 1, MD + 1, R);
        if (res >= B) res %= M;
        return res;
    }
};


inline char gc() { // like getchar()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++]; // returns 0 on EOF
}

#ifndef LOCAL
int readInt() {
    int a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}
#else
int readInt() {
    int x; cin >> x;
    return x;
}
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = readInt();
    int mod = readInt();
    vi a(n);
    f0r(i, n) a[i] = readInt();
    int q = readInt();
    vector<array<int, 4>> queries(q);
    f0r(i, q) {
        int t = readInt();
        queries[i][0] = t;
        if (t == 1) {
            f0r(j, 3) 
                queries[i][j + 1] = readInt();
        } else {
            f0r(j, 2) 
                queries[i][j + 1] = readInt();
        }
    }
    auto factors = factor(mod);
    LazySeg seg;
    vpl ans(q, {-1, -1});
    auto comb = [&](pl x, pl y) -> pi {
        if (x.f == -1) return y;
        if (y.f == -1) return x;
        return CRT(x, y);
    };
    each(f, factors) {
        int p = f.f;
        int e = f.s;
        int m = 1;
        f0r(i, e) m *= p;
        seg.init(a, p, e);
        int ti = 0;
        each(qq, queries) {
            int t = qq[0];
            if (t == 1) {
                int l = qq[1];
                int r = qq[2];
                int x = qq[3];
                l--, r--;
                seg.range(l, r, x);
            } else if (t == 2) {
                int id = qq[1];
                id--;
                int x = qq[2];
                seg.point(id, x);
            } else {
                int l = qq[1];
                int r = qq[2];
                l--, r--;
                auto res = seg.query(l, r);
                res %= m;
                pl use = mp(res, m);
                ans[ti] = comb(ans[ti], use);
            }
            ti++;
        }
    }
    each(x, ans) {
        if (x.f == -1) continue;
        cout << x.f << '\n';
    }
    return 0;
}