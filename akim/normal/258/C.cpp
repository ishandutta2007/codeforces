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

int a[maxn], n;

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
vector<int> vc, c;
int getans(int u) {
	vc.clear(), c.clear();
	for(int i = 1; i * i <= u; i++) if(u % i == 0){
		vc.pb(i), c.pb(0);
		if(i * i != u) vc.pb(u / i), c.pb(0);
	}
	sort(vc.begin(), vc.end());

	int m = vc.size();
	vc.pb(mod);
	for(int i = 0; i < m; i++) {
		c[i] = lower_bound(&a[0], &a[n], vc[i + 1]) - &a[0];
	}

	int ret = 1;
	c[m - 1] = n;
	for(int i = 0; i < m; i++) {
		ret = ret * 1ll * binpow(i + 1, c[i] - (i ? c[i - 1] : 0)) % mod;
	}
	int otn = 1;
	if(m > 1) {
		c[m - 2] = n;
		for(int i = 0; i < m - 1; i++) {
			otn = otn * 1ll * binpow(i + 1, c[i] - (i ? c[i - 1] : 0)) % mod;
		}
	} else {
		otn = 0;
	}
	return (ret - otn + mod) % mod;
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

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(&a[0], &a[n]);

	int ans = 0;
	for(int i = 1; i < maxn; i++) {
		ans = (ans + getans(i)) % mod;
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