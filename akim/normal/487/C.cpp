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

int binpow(int a, int b, int mod) {
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

	int n;
	scanf("%d", &n);
	if(n == 1) {
		printf("YES\n1\n");
		return(0);
	}
	if(n == 2) {
		printf("YES\n1\n2\n");
		return(0);
	}
	if(n == 3) {
		printf("YES\n1\n2\n3\n");
		return(0);
	}
	if(n == 4) {
		printf("YES\n1\n3\n2\n4\n");
		return(0);
	}
	bool ok = 1;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			ok = 0;
			break;
		}
	}
	if(!ok) {
		printf("NO\n");
		return(0);
	}
	printf("YES\n1\n");
	int pr = 1;
	for(int i = 2; i < n; i++) {
		int k = (i * 1ll * binpow(pr, n - 2, n)) % n;
		pr = pr * 1ll * k % n;
		printf("%d\n", k);
	}
	printf("%d\n", n);

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