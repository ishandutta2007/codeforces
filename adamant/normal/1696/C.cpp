#include <bits/stdc++.h>

using namespace std;

namespace lib {
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
};

#define int int64_t

const int mod = 1e9 + 7;

using base = lib::modular<mod>;

vector<pair<int, int>> canon(vector<int> a, int m) {
    vector<pair<int, int>> st;
    function<void(int, int)> push = [&](int it, int cnt = 1) {
        if(it % m) {
            if(st.empty() || st.back().first != it) {
                st.emplace_back(it, cnt);
            } else {
                st.back().second += cnt;
            }
        } else {
            push(it / m, cnt * m);
        }
    };
    for(auto it: a) {
        push(it, 1);
    }
    return st;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for(int j = 0; j < k; j++) {
        cin >> b[j];
    }
    if(canon(a, m) == canon(b, m)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}