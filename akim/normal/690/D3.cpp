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
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

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
const int mod = (int)1e+6 + 3;
const double pi = acos(-1.);
const int maxn = 100100;

ll sh[110];
ll dp[maxn];

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

	int c, w, h;
	scanf("%d%d%d", &c, &w, &h);

	sh[0] = 1;
	for(int i = 1; i <= w + 1; i++) {
		sh[i] = sh[i - 1] * 1ll * h % mod;
	}

	dp[0] = 1;
	dp[1] = 1;

	ll S = 1;
	int cc = c + 1;
	for(int i = 2, ii = 2; i <= c + 1; i++, ii++) {
		if(ii == maxn) {
			ii -= maxn;
			cc -= maxn;
		}
		dp[ii] = 0;
		S = S * h % mod;
		S = S + dp[ii - 1 >= 0 ? ii - 1 : ii - 1 + maxn];
		if(i - w - 1 > 0) {
			int fr = ii - w - 2;
			if(fr < 0) fr += maxn;
			S -= dp[fr] * sh[w + 1] % mod;
			S += S < 0 ? mod : 0;
		}
		dp[ii] = S;
		dp[ii] %= mod;
	}

	printf("%lld\n", dp[cc]);

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