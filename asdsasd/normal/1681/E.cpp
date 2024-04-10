#include<bits/stdc++.h>

#include <algorithm>

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

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

struct S{
    int l = -1;
    int r = -1;
    long long dxx = 0;
    long long dxy = 1 << 30;
    long long dyx = 1 << 30;
    long long dyy = 0;
};
const int N = 100100;
int n;
long long X[N], Y[N];
vector<S> A;

S e(){
    S ret;
    return ret;
}

S ope(S x, S y){
    if(x.l == -1) return y;
    if(y.l == -1) return x;
    S ret;
    ret.l = x.l;
    ret.r = y.r;
    long long x_x = abs(X[x.r] - X[y.l]);
    long long y_y = abs(Y[x.r] - Y[y.l]);
    long long x_y = min(2LL * (x.r + 1) - X[x.r] - Y[x.r] + y_y, 2LL * (y.l + 1) - X[x.r] - Y[y.l]);
    long long y_x = min(2LL * (x.r + 1) - X[x.r] - Y[x.r] + x_x, 2LL * (y.l + 1) - Y[x.r] - X[y.l]);
    ret.dxx = min(min(x.dxx + x_x + y.dxx, x.dxx + x_y + y.dyx), min(x.dxy + y_x + y.dxx, x.dxy + y_y + y.dyx));
    ret.dxy = min(min(x.dxx + x_x + y.dxy, x.dxx + x_y + y.dyy), min(x.dxy + y_x + y.dxy, x.dxy + y_y + y.dyy));
    ret.dyx = min(min(x.dyx + x_x + y.dxx, x.dyx + x_y + y.dyx), min(x.dyy + y_x + y.dxx, x.dyy + y_y + y.dyx));
    ret.dyy = min(min(x.dyx + x_x + y.dxy, x.dyx + x_y + y.dyy), min(x.dyy + y_x + y.dxy, x.dyy + y_y + y.dyy));
    return ret;
}

pair<long long, long long> dist(int ind, long long x, long long y){
    long long dx, dy;
    if(x == ind){
        dx = 2 * ind - X[ind - 1] - y;
        dy = abs(y - Y[ind - 1]);
    }else{
        dx = abs(x - X[ind - 1]);
        dy = 2 * ind - x - Y[ind - 1];
    }
    return {dx, dy};
}

pair<long long, long long> dist2(int ind, long long x, long long y){
    long long dx, dy;
    if(x == ind){
        dx = 2 * ind - X[ind - 2] - y;
        dy = abs(y - Y[ind - 2]);
    }else{
        dx = abs(x - X[ind - 2]);
        dy = 2 * ind - x - Y[ind - 2];
    }
    return {dx, dy};
}


void solve(){
    cin >> n;
    int zzz;
    A.resize(n-1);
    for(int i = 0; i < n - 1; i++){
        cin >> zzz >> Y[i] >> X[i] >> zzz;
        A[i].l = i;
        A[i].r = i;
    }
    segtree<S, ope, e> seg(A);
    int Q;
    cin >> Q;
    long long x1, y1, x2, y2, i1, i2;
    while(Q--){
        cin >> x1 >> y1 >> x2 >> y2;
        i1 = max(x1, y1);
        i2 = max(x2, y2);
        if(i1 == i2){
            if(x1 == x2 && x2 == i1){
                cout << abs(y1 - y2) << "\n";
            }
            else if(y1 == y2 && y2 == i1){
                cout << abs(x1 - x2) << "\n";
            }
            else if(x1 == y2 && y2 == i1){
                cout << 2 * i1 - y1 - x2 << "\n";
            }
            else{
                cout << 2 * i1 - x1 - y2 << "\n";
            }
            continue;
        }
        if(i1 > i2){
            swap(i1, i2);
            swap(x1, x2);
            swap(y1, y2);
        }
        auto tmp = seg.prod(i1 - 1, i2 - 1);
        auto d1 = dist(i1, x1, y1);
        auto d2 = dist2(i2, x2, y2);
        long long dx1 = d1.first;
        long long dy1 = d1.second;
        long long dx2 = d2.first;
        long long dy2 = d2.second;
        long long ans = dx1 + tmp.dxx + dx2;
        ans = min(ans, dx1 + tmp.dxy + dy2);
        ans = min(ans, dy1 + tmp.dyx + dx2);
        ans = min(ans, dy1 + tmp.dyy + dy2);
        ans += abs(i1 - i2);
        cout << ans << "\n";
    }

}

int main(){
	solve();
}