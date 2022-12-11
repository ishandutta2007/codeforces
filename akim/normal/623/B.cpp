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
const int maxn = 1000100;

ll x[maxn];
vector<ll> dels;

ll dp[maxn][3];

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

	ll n, a, b;
	scanf("%lld%lld%lld",&n, &a, &b);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}

	{
		for(int k = x[0] - 1; k <= x[0] + 1; k++) {
			int tar = k;
			int sq = sqrt(tar + 1);
			for(int i = 2; i <= sq; i++) {
				if(tar % i == 0) {
					dels.pb(i);
					while(tar % i == 0) {
						tar /= i;
					}
				}
			}
			if(tar > 1) dels.pb(tar);
		}
		for(int k = x[n - 1] - 1; k <= x[n - 1] + 1; k++) {
			int tar = k;
			int sq = sqrt(tar);
			for(int i = 2; i <= sq; i++) {
				if(tar % i == 0) {
					dels.pb(i);
					while(tar % i == 0) {
						tar /= i;
					}
				}
			}
			if(tar > 1) dels.pb(tar);
		}
		sort(dels.begin(), dels.end());
		dels.erase(unique(dels.begin(), dels.end()), dels.end());
	}

	ll ans = mod * 1ll * mod;

	for(int i = 0; i < (int)dels.size(); i++) {
		int g = dels[i];
		for(int j = 0; j < n; j++) {
			int ok = 0, price;
			int ost = x[j] % g;
			if(ost == 0) {
				price = 0;
				ok = 1;
			} else
			if(ost == 1 || ost == g - 1) {
				price = b;
				ok = 1;
			}
			if(ok) {
				dp[j][0] = (j ? dp[j - 1][0] : 0ll) + price;
				dp[j][1] = (j ? min(dp[j - 1][1], dp[j - 1][0]) : 0ll) + a;
				dp[j][2] = (j ? min(dp[j - 1][2], dp[j - 1][1]) : 0ll) + price;
			} else {
				dp[j][0] = mod * 1ll * mod;
				dp[j][1] = (j ? min(dp[j - 1][1], dp[j - 1][0]) : 0ll) + a;
				dp[j][2] = mod * 1ll * mod;
			}
		}
		ans = min(min(ans, dp[n - 1][0]), min(dp[n - 1][1], dp[n - 1][2]));
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