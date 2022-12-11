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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
ll mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll rt = 0, ra = 1, rb = 0, rc = 0, rd = 1;

void binpowmx(ll &a, ll &b, ll &c, ll &d, ll st) {
	while(st) {
		if(st & 1) {
			ll rra = ra, rrb = rb, rrc = rc, rrd = rd;
			ra = (rra * a + rrb * c) % mod;
			rb = (rra * b + rrb * d) % mod;
			rc = (rrc * a + rrd * c) % mod;
			rd = (rrc * b + rrd * d) % mod;
		}
		ll rra = a, rrb = b, rrc = c, rrd = d;
		a = (rra * rra + rrb * rrc) % mod;
		b = (rra * rrb + rrb * rrd) % mod;
		c = (rrc * rra + rrd * rrc) % mod;
		d = (rrc * rrb + rrd * rrd) % mod;
		st >>= 1;
	}
}

ll binpow(ll a, ll b) {
	ll rt = 1;
	while(b) {
		if(b & 1) {
			rt *= a;
			rt %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return(rt);
}

void calc(ll n) {
	ll a = 1, b = 1, c = 1, d = 0;
	binpowmx(a, b, c, d, n);
	rt = (ra + rb) % mod;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	ll n, k, l;
	scanf("%I64d%I64d%I64d%I64d", &n, &k, &l, &mod);

	if(l < 63 && k >= (1ll << l)) {
		printf("0");
		return(0);
	}

	calc(n);
	ll rrt = (binpow(2, n) + 2 * mod - rt) % mod;
	ll ans = 1;
	for(int i = 0; i < l; i++) {
		if(k & (1ll << i)) {
			ans *= rrt;
			ans %= mod;
		} else {
			ans *= rt;
			ans %= mod;
		}
	}

	printf("%I64d", ans % mod);

	return(0);
}

// by Kim Andrey