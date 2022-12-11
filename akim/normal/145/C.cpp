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
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int oth, c[1050], cnt;
int dp[2][1030];
map<int, int> id;

void getall(ll u) {
	ll l = u * 10 + 4;
	ll r = u * 10 + 7;
	if(l > mod) return;
	id[l] = cnt++;
	id[r] = cnt++;
	getall(l), getall(r);
	return;
}

int binpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) {
			ret = ret * 1ll * a % mod;
		}
		a = a * 1ll * a % mod;
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

	getall(0);

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		int u;
		scanf("%d", &u);
		bool p = id.count(u);
		if(p) {
			c[id[u]]++;
		} else {
			oth++;
		}
	}

	dp[0][0] = 1;
	for(int i = 0; i < 1030; i++) {
		for(int j = 0; j < 1030; j++) {
			dp[1 - (i & 1)][j] = dp[1 - (i & 1)][j] + dp[i & 1][j];
			dp[1 - (i & 1)][j] += dp[1 - (i & 1)][j] >= mod ? -mod : 0;
			dp[1 - (i & 1)][j + 1] = (dp[1 - (i & 1)][j + 1] + dp[i & 1][j] * 1ll * c[i]) % mod;
			dp[i & 1][j] = 0;
		}
	}

	int ans = 0, cnk = 1;
	for(int i = 0; i <= k; i++) {
		if(k - i < 1030) ans = (ans + cnk * 1ll * dp[0][k - i]) % mod;
		cnk = cnk * 1ll * (oth - i) % mod * binpow(i + 1, mod - 2) % mod;
	}
	printf("%d", ans);

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