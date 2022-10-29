#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long
#define ull unsigned long long

template <typename T>
T add(T a, T b, T m) {
	return ((a += b) >= m) ? (a - m) : (a);
}

template <typename T>
void pcopy(T* pst, const T* ped, T* pval) {
	for ( ; pst != ped; *(pst++) = *(pval++));
}

ll mul(ll a, ll b, ll m) {
	//    return (__int128)a * b % m;
	ll rt = 0, pa = a;
	for ( ; b; b >>= 1, pa = add(pa, pa, m))
		if (b & 1)
			rt = add(rt, pa, m);
	return rt;
}

ll qpow(ll a, ll p, ll m) {
	ll rt = 1, pa = a;
	for ( ; p; p >>= 1, pa = mul(pa, pa, m))
		if (p & 1)
			rt = mul(rt, pa, m);
	return rt;
}

ll gcd(ll a, ll b) {
	return (b) ? (gcd(b, a % b)) : (a);
}

ll randLL() {
	static ull seed = 998244353, msk = (1ull << 61) - 1;
	return (signed ll) ((seed = seed * seed + seed * 3 + 233) & msk);
}

boolean miller_rabin(ll n) {
	static int T = 25;
	static const int pri[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	if (!(n & 1))
		return n == 2;
	if (n < 1000) {
		for (int p = 2; p * p <= n; p++)
			if (!(n % p))
				return false;
		return true;
	}
	for (int i = 0; i < 10; i++) {
		if (n == pri[i]) {
			return true;
		} else if (!(n % pri[i])) {
			return false;
		}
	}
	ll d = n - 1;
	int s = 0;
	while (!(d & 1))
		s++, d >>= 1;
	for (int t = 0; t < T; t++) {
		ll b = randLL() % n;
		if (!b)
			continue;
		ll tmp = qpow(b, d, n);
		if (tmp == 1 || tmp == n - 1)
			continue;
		for (int i = 0; i < s; i++) {
			tmp = mul(tmp, tmp, n);
			if (tmp == n - 1)
				goto nextTurn;
			if (tmp == 1 || tmp == 0)
				return false;
		}
		if (tmp != 1)
			return false;
nextTurn:;
	}
	return true;
}

ll pollard_rho(ll x) {
//	cerr << x << '\n';
	ll a, b, c, g;
	if (!(x & 1))
		return 2;
	while (true) {
		b = a = randLL() % x;
		c = randLL() % 127 % x;
		do {
			a = add(mul(a, a, x), c, x);
			b = add(mul(b, b, x), c, x);
			b = add(mul(b, b, x), c, x);
			g = gcd(b - a, x);
			(g < 0) ? (g = -g) : (0);
			if (g == x)
				break;
			if (g > 1)
				return g;
		} while (a != b);
	}
	assert(false);
	return 0;
}

void get_primary_factors(ll x, vector<ll>& rt) {
	if (x == 1) {
		return;
	}
	if (miller_rabin(x)) {
		rt.push_back(x);
		return;
	}
	ll a = pollard_rho(x);
	get_primary_factors(a, rt);
	get_primary_factors(x / a, rt);
}

vector< pair<ll, int> > get_primary_factor(vector<ll>& vec) {
	vector< pair<ll, int> > rt;
	if (vec.empty())
		return rt;
	sort(vec.begin(), vec.end());
	vector<ll>::iterator it = vec.begin();
	rt.push_back(make_pair(*it, 1));
	for (it = it + 1 ; it != vec.end(); it++)
		if (*it == rt.back().first)
			rt.back().second++;
		else
			rt.push_back(make_pair(*it, 1));
	return rt;
}

/// Template ends

typedef vector<pair<ll, int>> factor;

int n;
ll m, p;
int g;
ll q, phim; // m = q^{alpha}
ll index, order;

void get_q() {
	vector<ll> tmp;
	get_primary_factors(m, tmp);
	q = tmp[0];
	phim = m / q * (q - 1);
}

factor fac;
void factor_m() {
	vector<ll> tmp;
	get_primary_factors(m, tmp);
	q = tmp[0];
	tmp.clear();
	get_primary_factors(phim = m / q * (q - 1), tmp);
	fac = get_primary_factor(tmp);
}

void get_primary_root() {
	if (m == 2) {
		g = 1;
		return;
	}
	for (g = 2; ; g++) {
		if (!(g % q)) {
			continue;
		}
		boolean aflag = true;
		for (auto par : fac) {
			if (qpow(g, phim / par.first, m) == 1) {
				aflag = false;
				break;
			}
		}
		if (aflag) {
			return;
		}
	}
}

int main() {
	scanf("%d%lld%lld", &n, &m, &p);
	if (gcd(m, p) != 1) {
		get_q();
		if (phim - 1 < n) {
			puts("-1");
		} else {
			for (int i = 2; n; i++) {
				if (i % q) {
					printf("%d ", i);
					n--;
				}
			}
		}
		return 0;
	}
	if ((m & 1) || m == 2 || m == 4) {
		factor_m();
		get_primary_root();
		order = phim;
		for (auto par : fac) {
			while (!(order % par.first) && qpow(p, order / par.first, m) == 1)
				order /= par.first;
		}
		index = phim / order;
		if (phim - order < n) {
			puts("-1");
			return 0;
		}
		ll prod = 1;
		for (int i = 1; n; i++) {
			prod = mul(prod, g, m);
			if (i % index) {
				printf("%lld ", prod);
				n--;
			}
		}
	} else {
		g = 5, q = 2;
		factor_m();
		if ((p & 3) == 1) {
			order = m >> 2;
			while (order > 1 && qpow(p, order >> 1, m) == 1)
				order >>= 1;
			index = (m >> 2) / order;
			if (phim - order < n) {
				puts("-1");
				return 0;
			}
			ll prod = 1;
			for (int i = 0; n; i++) {
				if (i % index) {
					printf("%lld ", prod);
					n--;
				}
				if (n) {
					printf("%lld ", m - prod);
					n--;
				}
				prod = mul(prod, g, m);
			}
		} else {
			order = m >> 2;
			while (order > 1 && qpow(p, order >> 1, m) == 1)
				order >>= 1;
			index = (m >> 2) / order;
			if (phim - order < n) {
				puts("-1");
				return 0;
			}
			ll prod = 1;
			for (int i = 0; n; i++) {
				if (!(i % index)) {
					int r = i / index;
					if (r & 1) {
						printf("%lld ", prod);
					} else {
						printf("%lld ", m - prod);
					}	
					n--;
				} else {
					printf("%lld ", prod), n--;
					if (n) printf("%lld ", m - prod), n--;
				}
				prod = mul(prod, g, m);
			}
		}
	}
	return 0;
}