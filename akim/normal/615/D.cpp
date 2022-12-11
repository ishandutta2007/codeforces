#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

ll pr[maxn];
ll prf[maxn], suf[maxn];

ll binpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) {
			ret *= a;
			ret %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return(ret);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		pr[p]++;
	}

	for(int i = 0; i < maxn; i++) {
		prf[i] = (pr[i] + 1) * (i - 1 >= 0 ? prf[i - 1] : 1);
		prf[i] %= mod - 1;
	}
	for(int i = maxn - 1; i >= 0; i--) {
		suf[i] = (pr[i] + 1) * (i + 1 < maxn ? suf[i + 1] : 1);
		suf[i] %= mod - 1;
	}

	ll ans = 1;
	for(int i = 0; i < maxn; i++) {
		if(!pr[i]) continue;
		ll pf = i - 1 >= 0 ? prf[i - 1] : 1;
		ll sf = i + 1 < maxn ? suf[i + 1] : 1;

		ll ch = 1;
		for(int j = 0; j < pr[i]; j++) {
			ch *= i;
			ch %= mod;
			ans *= binpow(ch, (pf * sf) % (mod - 1));
			ans %= mod;
		}
	}

	printf("%lld", ans);

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim