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
const int maxn = 1000100;

int dp[maxn], mx[maxn];
ll lw[maxn];

pair<ll, ll> rec(ll m) {
	if(m == 0) return(mp(0, 0));
	if(m == 1) return(mp(1, 1));
	ll v = upper_bound(&lw[1], &lw[maxn], m) - &lw[0] - 1, vvv = v * v * v;
	pair<ll, ll> rt1 = rec(m - vvv);
	rt1.fs++; rt1.sc += vvv;
	if(v == 1) {
		return(rt1);
	}
	ll u = v - 1, uuu = u * u * u;
	pair<ll, ll> rt2 = rec(vvv - 1 - uuu);
	rt2.fs++; rt2.sc += uuu;
	return(max(rt1, rt2));
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

	dp[0] = 0;
	dp[1] = 1;
	lw[1] = 1;
	for(int i = 2; i < maxn; i++) {
		lw[i] = i * 1ll * i * 1ll * i;
		int v = upper_bound(&lw[1], &lw[i + 1], i) - &lw[0] - 1;
		dp[i] = dp[i - v * v * v] + 1;
	}

	ll m;
	scanf("%lld", &m);
	pair<ll, ll> ans = rec(m);
	printf("%lld %lld", ans.fs, ans.sc);

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