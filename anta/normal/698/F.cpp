#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

vector<int> primes;
vector<int> smallestPrimeFactor;
void linearSieve(int n) {
	if(n < 1) n = 1;
	if((int)smallestPrimeFactor.size() >= n + 1) return;
	int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
	primes.assign(primePiBound + 1, numeric_limits<int>::max());
	int P = 0;
	smallestPrimeFactor.assign(n + 1, 0);
	smallestPrimeFactor[1] = 1;
	int n2 = n / 2, n3 = n / 3, n5 = n / 5;
	if(n >= 2)
		primes[P ++] = 2;
	if(n >= 3)
		primes[P ++] = 3;
	for(int q = 2; q <= n; q += 2)
		smallestPrimeFactor[q] = 2;
	for(int q = 3; q <= n; q += 6)
		smallestPrimeFactor[q] = 3;
	for(int q = 5; q <= n5; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
		int bound = smallestPrimeFactor[q];
		for(int i = 2; ; ++ i) {
			int p = primes[i];
			if(p > bound) break;
			int pq = p * q;
			if(pq > n) break;
			smallestPrimeFactor[pq] = p;
		}
	}
	for(int q = (n5 + 1) | 1; q <= n; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
	}
	primes.resize(P);
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> assigned(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &assigned[i]);
		linearSieve(n);
		vector<int> nextDivisor(n + 1);
		nextDivisor[1] = 1;
		rer(i, 2, n) {
			int p = smallestPrimeFactor[i];
			int j = i / p;
			while(j % p == 0) j /= p;
			nextDivisor[i] = j;
		}
		vector<int> rad(n + 1);
		vector<int> factorSetSize(n + 1);
		rad[1] = 1;
		factorSetSize[1] = 0;
		rer(i, 2, n) {
			rad[i] = smallestPrimeFactor[i] * rad[nextDivisor[i]];
			factorSetSize[i] = 1 + factorSetSize[nextDivisor[i]];
		}
		//factorSet(1) = {1} 
		factorSetSize[1] = 1;
		vector<int> radCount(n + 1);
		rer(i, 1, n)
			++ radCount[rad[i]];
		vector<int> groupSize(n + 1);
		groupSize[1] = 1;
		for(int p : primes) if(p <= n)
			groupSize[p] = n / p;
		vector<int> groupPerm(n + 1, -1), invGroupPerm(n + 1, -1);
		bool ok = true;
		rer(i, 1, n) {
			int j = assigned[i - 1];
			if(j == 0) continue;
			if(factorSetSize[i] != factorSetSize[j]) {
				ok = false;
				break;
			}
			//<http://codeforces.com/blog/entry/46675>
			//> The primes must be ordered because if q is less or equal than  then the only group with the same numbers of Gq is Gq, and if q is greater than  then q is the last prime in the list of x and the groups with the same number of Gq are those Gr where r is a prime greater than , which is also the last one
			//dvCc
			// assign I
			int size = factorSetSize[i];
			int x = i, y = j;
			rep(k, size) {
				int p = smallestPrimeFactor[x];
				int q = smallestPrimeFactor[y];
				ok &= groupSize[p] == groupSize[q];
				if(groupPerm[p] == -1) {
					groupPerm[p] = q;
					ok &= invGroupPerm[q] == -1;
					invGroupPerm[q] = p;
				} else {
					ok &= groupPerm[p] == q;
				}
				x = nextDivisor[x];
				y = nextDivisor[y];
			}
			if(!ok) break;
			-- radCount[rad[j]];
		}
		if(!ok) {
			puts("0");
			continue;
		}

		vector<int> unassignedCount(n + 1);
		rer(i, 1, n) if(groupSize[i] != 0 && groupPerm[i] == -1)
			++ unassignedCount[groupSize[i]];

		vector<mint> fact(n + 1);
		fact[0] = 1;
		rer(i, 1, n)
			fact[i] = fact[i - 1] * i;

		mint ans = 1;
		rer(i, 1, n)
			ans *= fact[unassignedCount[i]];
		rer(i, 1, n)
			ans *= fact[radCount[i]];

		printf("%d\n", ans.get());
	}
	return 0;
}