#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1 << 20;
const int mod = 998244353;

namespace algebra {
    const int magic = 250; // threshold for sizes to run the naive algo
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

    template<typename T>
    T bpow(T x, size_t n) {
        if(n == 0) {
            return T(1);
        } else {
            auto t = bpow(x, n / 2);
            t = t * t;
            return n % 2 ? x * t : t;
        }
    }

    template<int m>
    struct modular {
        int r;
        constexpr modular(): r(0) {}
        constexpr modular(int64_t rr): r(rr % m) {if(r < 0) r += m;}
        modular inv() const {return bpow(*this, m - 2);}
        modular operator - () const {return r ? m - r : 0;}
        modular operator * (const modular &t) const {return (int64_t)r * t.r % m;}
        modular operator / (const modular &t) const {return *this * t.inv();}
        modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
        modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
        modular operator + (const modular &t) const {return modular(*this) += t;}
        modular operator - (const modular &t) const {return modular(*this) -= t;}
        modular operator *= (const modular &t) {return *this = *this * t;}
        modular operator /= (const modular &t) {return *this = *this / t;}
        
        bool operator == (const modular &t) const {return r == t.r;}
        bool operator != (const modular &t) const {return r != t.r;}
        
        explicit operator int() const {return r;}
        int64_t rem() const {return 2 * r > m ? r - m : r;}
    };
    
    template<int T>
    istream& operator >> (istream &in, modular<T> &x) {
        return in >> x.r;
    }
    
    template<int T>
    ostream& operator << (ostream &out, modular<T> const& x) {
        return out << x.r;
    }
    
    typedef modular<mod> base;
    base F[maxn];
    
    base fact(int n) {
        static bool init = false;
        if(!init) {
            F[0] = base(1);
            for(int i = 1; i < maxn; i++) {
                F[i] = F[i - 1] * base(i);
            }
            init = true;
        }
        return F[n];
    }
    
    base RF[maxn];
    base rfact(int n) {
        static bool init = false;
        if(!init) {
            RF[maxn - 1] = base(1) / fact(maxn - 1);
            for(int i = maxn - 2; i >= 0; i--) {
                RF[i] = RF[i + 1] * base(i + 1);
            }
            init = true;
        }
        return RF[n];
    }
};

using namespace algebra;


base nCr(int n, int r) {
    assert(r >= 0 && r <= n);
    return fact(n) * rfact(r) * rfact(n - r);
}

base pairs(int n, int t) {
    assert(2 * t <= n && t >= 0);
    return nCr(n, 2 * t) * nCr(2 * t, t) * fact(t) * bpow(base(2).inv(), t);
}

base total[maxn];

base total_pairs(int m) {
    assert(m >= 0);
    if(m == 0 || m == 1) {
        return base(1);
    }
    if(total[m] == base(0)) {
        total[m] = total_pairs(m - 1) + base(m - 1) * total_pairs(m - 2);
    }
    return total[m];
}

base resol(int n) {
    base ans = 0;
    for(int k = 0; 4 * k <= n; k++) {
        int m = n - 4 * k;
        ans += total_pairs(m) * pairs(n - 2 * k, k) * bpow(base(2), k);
    }
    return ans;
}

base brute(int n) {
    int p[n];
    iota(p, p + n, 0);
    int ans = 0;
    do {
        int q[n];
        for(int i = 0; i < n; i++) {
            q[p[i]] = i;
        }
        bool bad = false;
        for(int i = 0; i < n; i++) {
            if(abs(p[i] - q[i]) > 1) {
                bad = true;
            }
        }
        ans += !bad;
    } while(next_permutation(p, p + n));
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << resol(n) << "\n";
}

signed main() {
    for(int i = 1; i <= 10; i++) {
        assert(resol(i) == brute(i));
    }
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}