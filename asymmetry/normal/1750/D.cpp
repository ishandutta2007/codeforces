#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

template<int mod>
struct modular {
	int val;
	modular() { val = 0; }
	modular(const LL& v) {
		val = int((-mod <= v && v < mod) ? (int) v : v % mod);
		if(val < 0) val += mod;
	}
	int to_int() { return val; }

	friend ostream& operator<<(ostream &os, const modular &a) {
#ifdef DEBUG
		constexpr int mx = 1024;
		for(int y = 1; y <= mx; ++y)
			if(a * y <= mx)
				return os << (a * y).val << '/' << y;
			else if(mod - a * y <= mx)
				return os << '-' << (mod - a * y).val << '/' << y;
#endif
		return os << a.val;
	}
	friend istream& operator>>(istream &is, modular &a) {
		return is >> a.val;
	}

	friend bool operator==(const modular &a, const modular &b) {
		return a.val == b.val;
	}
	friend bool operator!=(const modular &a, const modular &b) {
		return !(a == b);
	}
	friend bool operator<(const modular &a, const modular &b) {
		return a.val < b.val;
	}
	friend bool operator<=(const modular &a, const modular &b) {
		return a.val <= b.val;
	}

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular &m) {
		if((val += m.val) >= mod) val -= mod;
		return *this;
	}
	modular& operator-=(const modular &m) {
		if((val -= m.val) < 0) val += mod;
		return *this;
	}
	modular& operator*=(const modular &m) {
		val = int((LL) val * m.val % mod);
		return *this;
	}
	friend modular qpow(modular a, LL n) {
		if(n == 0) return 1;
		if(n % 2 == 1) return qpow(a, n - 1) * a;
		return qpow(a * a, n / 2);
	}
	friend modular inv(const modular &a) {
		assert(a != 0); return qpow(a, mod - 2);
	}
	modular& operator/=(const modular &m) { 
		return (*this) *= inv(m); 
	}
	modular operator++(int) {
		modular res = (*this);
		(*this) += 1;
		return res;
	}

	friend modular operator+(modular a, const modular &b) { return a += b; }
	friend modular operator-(modular a, const modular &b) { return a -= b; }
	friend modular operator*(modular a, const modular &b) { return a *= b; }
	friend modular operator/(modular a, const modular &b) { return a /= b; }
};
using mint = modular<998244353>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int tests;
    cin >> tests;
    REP (test, tests) {
        int n, m;
        cin >> n >> m;
        vector<int> t(n);
        REP (i, n) {
            cin >> t[i];
        }
        bool brk = false;
        FOR (i, 1, n - 1) {
            if (t[i - 1] % t[i]) {
                brk = true;
            }
        }
        if (brk) {
            cout << 0 << endl;
            continue;
        }
        mint odp = 1;
        vector<int> pri;
        int nn = t[0];
        for (int i = 2; i * i <= nn; ++i) {
            if (nn % i == 0) {
                pri.emplace_back(i);
                while (nn % i == 0) {
                    nn /= i;
                }
            }
        }
        if (nn > 1) {
            pri.emplace_back(nn);
        }

        auto ways = [&](int x, int M) {
            debug(x, M);
            vector<int> akt;
            for (int i : pri) {
                if (x % i == 0) {
                    akt.emplace_back(i);
                }
            }
            debug(akt);
            int g = ssize(akt);
            mint ret = 0;
            REP (i, 1 << g) {
                int cur = M;
                REP (j, g) {
                    if ((i >> j) & 1) {
                        cur /= akt[j];
                    }
                }
                if (__builtin_parity(i)) {
                    ret -= cur;
                }
                else {
                    ret += cur;
                }
            }
            debug(ret);
            return ret;
        };

        FOR (i, 1, n - 1) {
            odp *= ways(t[i - 1] / t[i], m / t[i]);
        }
        cout << odp << endl;
    }
}