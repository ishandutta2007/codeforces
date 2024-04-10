#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include <iostream>
#include <vector>
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
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
            if (((r >> i) << i) != r) push(r >> i);
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
using namespace atcoder;

struct S{
    long long tot = 0;
    long long size = 0;
};
using F = long long;
S op(S l, S r){
    return {l.tot + r.tot, l.size + r.size};
}

S e(){
    return S{0, 0};
}

S mapping(F l, S r){
    return S{r.tot + r.size * l, r.size};
}

F composition(F l, F r){
    return l + r;
}

F id(){
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> C(n, vector<int>(3));
    set<int> se;
    for(int i = 0; i < n; i++){
        cin >> C[i][1] >> C[i][2] >> C[i][0];        
        C[i][3] = i;
        se.insert(C[i][1]);
        se.insert(C[i][2]);
    }
    map<int, int> mp;
    int ind = 0;
    vector<int> lst;
    for(auto s:se) mp[s] = ind++, lst.push_back(s);
    int le = mp.size();
    vector<S> A(le + 1, S{0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
    sort(C.begin(), C.end());
    int l, r, jj, c;
    int bc = -1;
    vector<int> ans(n, 1 << 30);
    vector<pair<int, int>> add;    
    for(int i = 0; i < n; i++){
        c = C[i][0];
        l = mp[C[i][1]];
        r = mp[C[i][2]];
        jj = C[i][3];
        if(c != bc){
            bc = c;
            for(auto tmp:add){
                seg.apply(tmp.first, tmp.second + 1, 1);
            }
            add.clear();
        }
        add.push_back({l, r});
        long long ll, rr;
        if(l == 0) ll = 0;
        else ll = seg.prod(0, l).tot;
        rr = seg.prod(0, r + 1).tot;
        if(ll != rr){            
            ans[jj] = 0;
            continue;
        } 
        
        if(ll != 0){
            int p = seg.min_left(l, [&](S x){
                return x.tot <= 0;
            });            
            ans[jj] = min(ans[jj], lst[l] - lst[p - 1]);
        }        
        if(rr < seg.prod(0, le + 1).tot){
            int p = seg.max_right(r + 1, [&](S x){
                return x.tot <= 0;
            });
            ans[jj] = min(ans[jj], lst[p] - lst[r]);
        }
    }

    bc = -1;
    vector<S> B(le + 1, S{0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg2(B);
    add.clear();
    for(int i = n - 1; i >= 0; i--){
        c = C[i][0];
        l = mp[C[i][1]];
        r = mp[C[i][2]];
        jj = C[i][3];
        if(c != bc){
            bc = c;
            for(auto tmp:add){
                seg2.apply(tmp.first, tmp.second + 1, 1);
            }
            add.clear();
        }
        add.push_back({l, r});
        long long ll, rr;
        if(l == 0) ll = 0;
        else ll = seg2.prod(0, l).tot;
        rr = seg2.prod(0, r + 1).tot;
        if (jj == 7){
        }
        if(ll != rr){
            ans[jj] = 0;
            continue;
        }
        if(ll != 0){
            int p = seg2.min_left(l, [&](S x){
                return x.tot <= 0;
            });
            ans[jj] = min(ans[jj], lst[l] - lst[p - 1]);
        }
        if(rr < seg2.prod(0, le + 1).tot){
            int p = seg2.max_right(r + 1, [&](S x){
                return x.tot <= 0;
            });
            ans[jj] = min(ans[jj], lst[p] - lst[r]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i];
        if(i == n - 1) cout << "\n";
        else cout << " ";
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}