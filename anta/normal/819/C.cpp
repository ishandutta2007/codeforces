#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


vector<int> primes;
vector<int> smallestPrimeFactor;
void linearSieve(int n) {
	if (n < 1) n = 1;
	if ((int)smallestPrimeFactor.size() >= n + 1) return;
	int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
	primes.assign(primePiBound + 1, numeric_limits<int>::max());
	int P = 0;
	smallestPrimeFactor.assign(n + 1, 0);
	smallestPrimeFactor[1] = 1;
	int n2 = n / 2, n3 = n / 3, n5 = n / 5;
	if (n >= 2)
		primes[P ++] = 2;
	if (n >= 3)
		primes[P ++] = 3;
	for (int q = 2; q <= n; q += 2)
		smallestPrimeFactor[q] = 2;
	for (int q = 3; q <= n; q += 6)
		smallestPrimeFactor[q] = 3;
	for (int q = 5; q <= n5; q += 2) {
		if (smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
		int bound = smallestPrimeFactor[q];
		for (int i = 2; ; ++ i) {
			int p = primes[i];
			if (p > bound) break;
			int pq = p * q;
			if (pq > n) break;
			smallestPrimeFactor[pq] = p;
		}
	}
	for (int q = (n5 + 1) | 1; q <= n; q += 2) {
		if (smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
	}
	primes.resize(P);
}

typedef int FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	linearSieve(x);
	out_v.clear();
	while (x != 1) {
		int p = smallestPrimeFactor[x], k = 0;
		x /= p, k ++;
		while (x % p == 0) x /= p, k ++;
		out_v.push_back(make_pair(p, k));
	}
}

struct P {
	typedef int T; typedef ll T2;	//T2{a^2 | a:T}
	T x, y;
	P(T x_, T y_) : x(x_), y(y_) {}
	P() : x(0), y(0) {}
};
P::T2 cross(const P& a, const P& b) { return (P::T2)a.x*b.y - (P::T2)a.y*b.x; }
ll area2(P a, P b, P c) {
	return abs(cross(a, b) + cross(b, c) + cross(c, a));
}

template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }

int main() {
	linearSieve(1000000);
	int T;
	scanf("%d", &T);
	for (int ii = 0; ii < T; ++ ii) {
		auto input = [&](map<int, int> &fs) -> ll {
			int A; int B; int C;
			scanf("%d%d%d", &A, &B, &C);
			Factors v;
			for (int x : {A, B, C}) {
				primeFactors(x, v);
				for (auto p : v)
					fs[p.first] += p.second;
			}
			return (ll)A * B * C;
		};
		map<int, int> fsN, fsM, fsS;
		ll M = input(fsM);
		ll N = input(fsN);
		ll S = input(fsS);
		++ fsS[2];
		vector<ll> constraints;
		for (auto p : fsM) {
			int x = fsS.count(p.first) ? fsS[p.first] : 0;
			if (x < p.second) {
				ll y = 1;
				rep(k, x) y *= p.first;
				if (y <= N / p.first) {
					y *= p.first;
					constraints.push_back(y);
				}
			}
		}
		ll ans = 0;
		rep(S, 1 << (int)constraints.size()) {
			ll n = N;
			int sign = 1;
			rep(i, constraints.size()) if (S >> i & 1) {
				sign = -sign;
				n /= constraints[i];
			}
			ans += sign * n;
		}
		vector<ll> divisors = {1};
		for(auto p : fsS) if(p.first != 2) {
			for (int j = (int)divisors.size() - 1; j >= 0; j --) {
				ll x = divisors[j];
				rep(k, p.second) {
					x *= p.first;
					if(x <= M)
						divisors.push_back(x);
				}
			}
		}
		{
			int t2 = fsS[2];
			for (ll x : divisors) {
				ll y = x;
				if (y <= M) {
					++ ans;
					rep(k, t2) {
						y *= 2;
						if (y <= M) {
							++ ans;
						} else {
							break;
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}