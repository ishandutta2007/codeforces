#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

int mod, phi;
basic_string<int> fact;

int mul(int a, int b, int m) {
	int x = (long double)a * b / m;
	return a * b - x * m;
}

template<typename T>
T bpow(T x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
}

struct base {
	int r;
	
	void normalize() {
		r = (r % mod + mod) % mod;
	}
	
	base():r(0){}
	base(int r):r(r){normalize();}
	
	base inv() const {return bpow(*this, phi - 1);}
	base operator += (const base &t){return *this = base(r + t.r);}
	base operator -= (const base &t){return *this = base(r - t.r);}
	base operator *= (const base &t){return *this = base(mul(r, t.r, mod));}
	base operator /= (const base &t){return *this *= t.inv();}
	base operator + (const base &t) const {return base(*this) += t;}
	base operator - (const base &t) const {return base(*this) -= t;}
	base operator * (const base &t) const {return base(*this) *= t;}
	base operator / (const base &t) const {return base(*this) /= t;}
	operator int() {return r;}
};

int rnd16() {
	return rand() & ((1 << 16) - 1);
}
int rnd48() {
	return rnd16() + (rnd16() << 16) + (rnd16() << 32);
}

base f(base x) {
	return x * x + (base)1;
}

int rho(int n) {
	mod = n;
	for(int z = 0; z < 10; z++) {
		base x = f(rnd48());
		base y = f(x);
		int g = __gcd(abs(x - y), n);
		int counter = 1e5;
		while(g == 1 && counter--) {
			x = f(x);
			y = f(f(y));
			g = __gcd(abs(x - y), n);
		}
		if(g != 1 && g != n) {
			return g;
		}
	}
	return n;
}

basic_string<int> factorize(int n) {
	if(n == 1) {
		return {};
	} else {
		int t = n % 2 ? rho(n) : 2;
		if(t == n) {
			return {n};
		} else {
			return factorize(t) + factorize(n / t);
		}
	}
}

int order(base x) {
	if(__gcd((int)x, mod) != 1) {
		return 1;
	} else {
		int res = phi;
		for(auto it: fact) {
			while(res % it == 0 && bpow(x, res / it) == 1) {
				res /= it;
			}
		}
		return res;
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	int n, m, p;
	cin >> n >> m >> p;
	fact = factorize(m);
	phi = m / fact[0] * (fact[0] - 1);
	//cout << phi << endl;
	fact = factorize(phi);
	mod = m;
	int ord = order(p);
	base idx = 1;
	if(ord + n > phi) {
		cout << -1 << endl;
	} else if(ord >= n) {
		if(m % 2 == 0) {
			idx = -1;
		} else {
			while(bpow(idx, ord) == 1 || __gcd((int)idx, m) != 1) {
				idx += 1;
			}
		}
		for(int i = 0; i < n; i++) {
			cout << idx * bpow((base)p, i) << ' ';
		}
	} else {
		set<int> bad;
		for(int i = 0; i < n; i++) {
			bad.insert(bpow((base)p, i));
		}
		for(int i = 0; i < n; i++, idx += 1) {
			while(bad.count(idx) || __gcd((int)idx, m) != 1) {
				idx += 1;
			}
			cout << idx << ' ';
		}
	}
	return 0;
}