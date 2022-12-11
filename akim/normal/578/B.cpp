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
const int maxn = 100100;

ll a[2 * maxn];
ll cnt[65];
ll ans[65] = {0};

void compare() {

	for(int i = 64; i >= 0; i--) {
		bool as = (ans[i] > 0);
		bool ct = (cnt[i] > 0);
		if(ct > as) {
			break;
		} else
		if(as > ct) {
			return;
		}
	}

	for(int i = 0; i < 64; i++) {
		ans[i] = cnt[i];
	}

}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	ull n, k, x;
	scanf("%I64d%I64d%I64d", &n, &k, &x);

	for(int i = 0; i < (int)n; i++) {
		scanf("%I64d", &a[i]);
		for(int f = 0; f < 64; f++) {
			if(a[i] & (1ll << f)) {
				cnt[f]++;
			}
		}
	}

	ll umn = 1;
	for(int i = 0; i < (int)k; i++) {
		umn *= x;
	}

	for(int i = 0; i < (int)n; i++) {
		for(int f = 0; f < 64; f++) {
			if(a[i] & (1ll << f)) {
				cnt[f]--;
			}
		}
		ll x = a[i] * umn;
		for(int f = 0; f < 64; f++) {
			if(x & (1ll << f)) {
				cnt[f]++;
			}
		}

		compare();

		for(int f = 0; f < 64; f++) {
			if(x & (1ll << f)) {
				cnt[f]--;
			}
		}

		for(int f = 0; f < 64; f++) {
			if(a[i] & (1ll << f)) {
				cnt[f]++;
			}
		}
	}

	ll ret = 0;
	for(int i = 0; i < 64; i++) {
		if(ans[i] > 0) {
			ret |= (1ll << i);
		}
	}

	printf("%I64d", ret);

	return(0);
}

// by Kim Andrey