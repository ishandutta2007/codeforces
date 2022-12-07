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

/*
 * Opis: Struktura do dziaa modulo
 * Czas: O(1), dzielenie O(\log mod)
 * Uycie: Ustaw modulo w ostatniej linii. Jeli modulo nie jest const, usu pierwszy wiersz i zadeklaruj mod
 */

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
using mint = modular<int(1e9 + 7)>;
// using mint = modular<998244353>;

struct BinomCoeff {
	vector<mint> fac, rev;
	BinomCoeff(int n) {
		fac = rev = vector<mint>(n + 1, 1);
		FOR(i, 1, n) fac[i] = fac[i - 1] * i;
		rev[n] = 1 / fac[n];
		for(int i = n; i >= 1; i--)
			rev[i - 1] = rev[i] * i;
	}
	mint operator()(int n, int k) {
		return fac[n] * rev[n - k] * rev[k];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tests;
	cin >> tests;
	REP (test, tests) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		vector<mint> dp(n + 1), sum(n + 2);
		dp[n] = 2;
		sum[n] = 2;
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = sum[i + 1] - sum[min(i * 2, n + 1)];
			sum[i] = sum[i + 1] + dp[i];
		}
		debug(dp);
		mint g = mint(1) / qpow(mint(2), n);
		FOR (i, 1, n - 1) {
			cout << dp[i] * qpow(mint(2), i / 2) * g << '\n';
		}
		cout << dp[n] * qpow(mint(2), n / 2) * g << '\n';
	}
}