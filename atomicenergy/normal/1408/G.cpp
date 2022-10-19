
using namespace std;

//#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;





template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt< 998244353 >;

#ifdef visual
static uint32_t __inline __builtin_ctz(uint32_t x)
{
    unsigned long r = 0;
    _BitScanForward(&r, x);
    return r;
}
#endif

template< typename Mint >
struct NTT {

    vector< Mint > dw, idw;
    int max_base;
    Mint root;

    NTT() {
        const unsigned mod = Mint::get_mod();
        assert(mod >= 3 && mod % 2 == 1);
        auto tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0) tmp >>= 1, max_base++;
        root = 2;
        while (root.pow((mod - 1) >> 1) == 1) root += 1;
        assert(root.pow(mod - 1) == 1);
        dw.resize(max_base);
        idw.resize(max_base);
        for (int i = 0; i < max_base; i++) {
            dw[i] = -root.pow((mod - 1) >> (i + 2));
            idw[i] = Mint(1) / dw[i];
        }
    }

    void ntt(vector< Mint >& a) {
        const int n = (int)a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = n; m >>= 1;) {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j] * w;
                    a[i] = x + y, a[j] = x - y;
                }
                w *= dw[__builtin_ctz(++k)];
            }
        }
    }

    void intt(vector< Mint >& a, bool f = true) {
        const int n = (int)a.size();
        assert((n & (n - 1)) == 0);
        assert(__builtin_ctz(n) <= max_base);
        for (int m = 1; m < n; m *= 2) {
            Mint w = 1;
            for (int s = 0, k = 0; s < n; s += 2 * m) {
                for (int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = a[i], y = a[j];
                    a[i] = x + y, a[j] = (x - y) * w;
                }
                w *= idw[__builtin_ctz(++k)];
            }
        }
        if (f) {
            Mint inv_sz = Mint(1) / n;
            for (int i = 0; i < n; i++) a[i] *= inv_sz;
        }
    }

    vector< Mint > multiply(vector< Mint > a, vector< Mint > b) {
        //reverse(a.begin(), a.end());
        //reverse(b.begin(), b.end());
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need) nbase++;
        int sz = 1 << nbase;
        a.resize(sz, 0);
        b.resize(sz, 0);
        ntt(a);
        ntt(b);
        Mint inv_sz = Mint(1) / sz;
        for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;
        intt(a, false);
        a.resize(need);
        //reverse(a.begin(), a.end());
        return a;
    }
};

NTT<mint> ntt;

vector<vector<mint> > all;

struct uf {
    vector<int> rt, sz, ed;

    uf(int n) {
        rt.resize(n);
        sz.resize(n);
        ed.resize(n);
        for (int i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
            ed[i] = 0;
        }
    }

    int id(int x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(int x, int y) {
        x = id(x);
        y = id(y);
        ed[y]++;
        if (x == y) return false;
        rt[x] = rt[y];
        sz[y] += sz[x];
        ed[y] += ed[x];
        all[y] = ntt.multiply(all[x], all[y]);
        ed[x] = 0;
        sz[x] = 0;
        return true;
    }
};




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int> > > v;
    uf uf(n);
    all.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i >= j) continue;
            v.push_back({ x, {i, j} });
        }
        all[i] = { 0, 1 }; //0 ways to make 0 sets, 1 ways to make 1 set
    }
    sort(v.begin(), v.end());
    for (auto p : v) {
        uf.join(p.second.first, p.second.second);

        ll a = uf.ed[uf.id(p.second.first)];
        ll b = uf.sz[uf.id(p.second.first)];
        if (a == (b * (b - 1)) / 2) {
            //cout << "here!" << endl;
            all[uf.id(p.second.first)][1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << all[uf.id(0)][i] << " ";
    }
    


}