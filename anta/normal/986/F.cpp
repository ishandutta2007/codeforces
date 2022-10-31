#include "bits/stdc++.h"
using namespace std;


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

template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

typedef long long FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	out_v.clear();
	int sqrtx = (int)sqrt((double)x);
	while ((long long)sqrtx * sqrtx < x) ++ sqrtx;
	for (vector<int>::const_iterator p = primes.begin(); p != primes.end(); ++ p) {
		if (*p > sqrtx) break;
		if (x % *p == 0) {
			int t = 1;
			x /= *p;
			while (x % *p == 0) {
				t ++;
				x /= *p;
			}
			out_v.push_back(make_pair(*p, t));
		}
	}
	if (x != 1) out_v.push_back(make_pair(x, 1));
}

template<typename T, typename U>
inline auto floordiv(T x, U y) -> decltype(x / y) {
	auto q = x / y, r = x % y;
	return q - ((r != 0) & ((r<0) ^ (y<0)));
}

// \min_{x=xL}^xU c floor((ax+b)/m)+dx+e
long long linearFloorDivMin(long long xL, long long xU, long long m, long long a, long long b, long long c, long long d, long long e) {
	assert(m != 0);
	if (xL > xU)
		return numeric_limits<long long>::max();
	if (m < 0) {
		m = -m, a = -a, b = -b;
	}
	if (xL != 0) {
		b += a * xL, e += d * xL, xU -= xL, xL = 0;
	}
	if (a < 0 || a >= m) {
		auto q = floordiv(a, m);
		a -= m * q, d += c * q;
	}
	if (b < 0 || b >= m) {
		auto q = floordiv(b, m);
		b -= m * q, e += c * q;
	}
	if (a == 0) {
		return min(0LL, d * xU) + e;
	}
	auto u = floordiv(a * xU + b, m);
	//     y = floor((ax+b)/m)
	// <-> y <= (ax+b)/m < y + 1
	// <-> (my-b)/a <= x < (my+m-b)/a

	// \min_{y=0}^u cy+d f(y)+e
	//  f(y) = floor((my-b+a-1)/a) if d >= 0 and y > 0
	//  f(y) = floor((my+m-b-1)/a) if d <  0 and y < u
	auto fb = d >= 0 ? -b + a - 1 : m - b - 1;
	if (d >= 0) {
		auto p = linearFloorDivMin(1, u, a, m, fb, d, c, e);
		auto q = e;						// y = 0, x = 0
		return min(p, q);
	} else {
		auto p = linearFloorDivMin(0, u - 1, a, m, fb, d, c, e);
		auto q = c * u + d * xU + e;	// y = u, x = xU
		return min(p, q);
	}
}
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

int main() {
	int T;
	scanf("%d", &T);
	long long maxK = 0;
	map<long long, vector<pair<long long, int>>> cases;
	for (int ii = 0; ii < T; ++ ii) {
		long long n; long long k;
		scanf("%lld%lld", &n, &k);
		cases[k].emplace_back(n, ii);
		amax(maxK, k);
	}
	linearSieve((int)sqrt((double)maxK) + 2);
	vector<int> ans(T, -1);
	for (const auto &kc : cases) {
		auto K = kc.first;
		Factors fs;
		primeFactors(K, fs);

		if (fs.empty()) {
			for (auto t : kc.second)
				ans[t.second] = 0;
		} else if (fs.size() == 1) {
			auto p = fs[0].first;
			for (auto t : kc.second)
				ans[t.second] = t.first % p == 0 ? 1 : 0;
		} else if (fs.size() == 2) {
			int p = (int)fs[0].first;
			auto q = fs[1].first;
			for (auto t : kc.second) {
				auto n = t.first;
				//\min_{x=0}^{n/q} ((n-qx) mod p)
				auto minMod = linearFloorDivMin(0, n / q, p, -q, n, -p, -q, n);
				ans[t.second] = minMod == 0 ? 1 : 0;
			}
		} else {
			const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
			int p = (int)fs[0].first;
			for (auto f : fs) assert(p <= f.first);
			vector<long long> minN(p, INFL);
			priority_queue<pair<long long, int>> pq;
			vector<bool> vis(p);
			int qt = 0;
			minN[0] = 0;
			pq.push(make_pair(-0LL, 0));
			while (!pq.empty()) {
				int i = pq.top().second;
				pq.pop();
				if (vis[i]) continue;
				vis[i] = true;
				auto x = minN[i];
				for (auto f : fs) if (f.first != p) {
					auto y = x + f.first;
					int j = y % p;
					if (y < minN[j]) {
						minN[j] = y;
						pq.push(make_pair(-y, j));
					}
				}
			}
			for (auto t : kc.second)
				ans[t.second] = minN[t.first % p] <= t.first ? 1 : 0;
		}
	}

	for (int x : ans)
		puts(x != 0 ? "YES" : "NO");
}