#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

ll modmult(ll x, ll y, ll MOD) {
	ll a = x, r = 0;
	while(y) {
		if(y & 1)
			if((r += a) >= MOD) r -= MOD;
		if((a += a) >= MOD) a -= MOD;
		y >>= 1;
	}
	return r;
}
ll powmodll(ll a, unsigned long long k, const ll MOD) {
	a %= MOD;
	ll r = MOD == 1 ? 0 : 1;
	while(k) {
		if(k & 1)
			r = modmult(r, a, MOD);
		a = modmult(a, a, MOD);
		k >>= 1;
	}
	return r;
}

bool suspect(ll a, int s, ll d, ll n) {
	ll x = powmodll(a, d, n);
	if(x == 1) return true;
	for(int r = 0; r < s; ++r) {
		if(x == n - 1) return true;
		x = modmult(x, x, n);
	}
	return false;
}

bool isPrime(ll n) {
	if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
	int test[] = {2,3,5,7,11,13,17,19,23,-1};
	ll d = n - 1; int s = 0;
	while (d % 2 == 0) ++ s, d /= 2;
	for(int i = 0; test[i] < n && test[i] != -1; ++i)
		if(!suspect(test[i], s, d, n)) return false;
	return true;
}

long long pow_ll_saturated(long long a, int k, long long upper) {
	if(upper < 1) return upper;
	const int X = 100;
	long long r = 1;
	while(k) {
		if(k & 1)
			r *= a;
		if(k >>= 1) {
			if((double)a * a * r - X > upper) return upper;
			a *= a;
		}
	}
	return r > upper ? upper : r;
}

void check(ll x, vector<ll> &v) {
	if(x <= 1) return;
	for(int k = 1; k <= 40; ++ k) {
		ll n = (ll)pow(x * 1., 1. / k);
		while(pow_ll_saturated(n, k, x+100) < x) ++ n;
		while(pow_ll_saturated(n, k, x+100) > x) -- n;
		if(pow_ll_saturated(n, k, x+1) != x) continue;
		if(isPrime(n)) {
//			cerr << "check: " << n << ", " << k << ": " << x << endl;
			v.push_back(n);
			return;
		}
	}
}

int main() {
	//J() is multiplicative
	//J(p^k) = p^k + 1
	long long A;
	while(cin >> A) {
		vector<ll> v;
		for(int i = 1; (ll)i * i <= A; ++ i) if(A % i == 0) {
			{	ll d = i;
				check(d - 1, v);
			}
			if((ll)i * i == A) continue;
			{	ll d = A / i;
				check(d - 1, v);
			}
		}
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		map<ll,ll> dp, ndp;
		ndp[1] = 1;
		each(p, v) {
			dp = ndp;
			ll pk = *p;
			while(pk + 1 <= A) {
				ll d = pk + 1;
				ll mx = A / d;
				each(i, dp) {
					if(i->first > mx) break;
					ll e = i->first * d;
					if(A % e == 0)
						ndp[e] += i->second;
				}
				if(pk * 1. * *p > 1e13) break;
				pk *= *p;
			}
		}
		ll ans = ndp[A];
		cout << ans << endl;
	}
	return 0;
}