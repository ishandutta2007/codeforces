#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	if ((int)isprime.size() >= n + 1) return;
	isprime.assign(n + 1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for (int i = 2; i <= sqrtn; i ++) if (isprime[i]) {
		for (int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for (int i = 2; i <= n; i ++) if (isprime[i])
		primes.push_back(i);
}

typedef long long FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	out_v.clear();
	int sqrtx = (int)(sqrt(x*1.) + 10.5);
	sieve(sqrtx);
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

ll phi(ll n) {
	Factors fs;
	primeFactors(n, fs);
	ll r = n;
	for (auto &&f : fs)
		r -= r / f.first;
	return r;
}

ll solve(ll n, ll k) {
	if (k <= 0) return n;
	if (k % 2 == 0)
		return solve(n, k - 1);
	else
		return phi(solve(n, k - 1));
}

int main() {
	sieve((int)2e6);
	long long n; long long k;
	while (~scanf("%lld%lld", &n, &k)) {
		ll ans = k >= 128 ? 1 : solve(n, k);
		ans %= (int)1e9 + 7;
		printf("%lld\n", ans);
	}
	return 0;
}