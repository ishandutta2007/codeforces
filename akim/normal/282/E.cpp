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
/*tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;*/
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

int bor[64*maxn][2], sz = 1;
ll a[maxn];
ll x[maxn];

void add(ll u) {
	int cur = 0;
	for(int i = 45; i >= 0; i--) {
		ll v = (u >> i) & 1;
		if(!bor[cur][v]) {
			bor[cur][v] = sz++;
		}
		cur = bor[cur][v];
	}
}

ll get(ll u) {
	int cur = 0;
	ll ret = 0;
	for(int i = 45; i >= 0; i--) {
		ll v = 1 -((u >> i) & 1), add = 1;
		if(!bor[cur][v]) {
			v = 1 - v, add = 0;
		}
		ret |= (add << i);
		cur = bor[cur][v];
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
		scanf("%lld", &a[i]);
		x[i] = (i ? x[i - 1] : 0ll) ^ a[i];
	}
	ll ans = 0;
	ll cur = 0;
	for(int i = n - 1; i >= 0; i--) {
		add(cur);
		ans = max(ans, get(x[i]));
		cur ^= a[i];
	}
	ans = max(ans, get(0));
	printf("%lld\n", ans);

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