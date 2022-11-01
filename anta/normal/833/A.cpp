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

int main() {
	vector<ll> cubes(1000001);
	rep(i, 1000001)
		cubes[i] = (ll)i * i * i;
	linearSieve(1000000);
	int Q;
	while (~scanf("%d", &Q)) {
		rep(ii, Q) {
			int A; int B;
			scanf("%d%d", &A, &B);
			ll prod = (ll)A * B;
			int C = (int)(lower_bound(cubes.begin(), cubes.end(), prod) - cubes.begin());
			bool ans;
			if (C == cubes.size() || cubes[C] != prod) {
				ans = false;
			} else {
				Factors fs;
				primeFactors(C, fs);
				ans = true;
				for (auto pp : fs) {
					int p = pp.first;
					int a = 0, b = 0;
					while (A % p == 0) ++ a, A /= p;
					while (B % p == 0) ++ b, B /= p;
					ans &= max(a, b) <= min(a, b) * 2;
				}
				assert(A == 1 && B == 1);
			}
			puts(ans ? "Yes" : "No");
		}
	}
	return 0;
}