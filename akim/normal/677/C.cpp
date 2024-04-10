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

int f(char c) {
	int ret;
	if(c >= '0' && c <= '9') ret = c - '0';
	if(c >= 'A' && c <= 'Z') ret = c - 'A' + 10;
	if(c >= 'a' && c <= 'z') ret = c - 'a' + 36;
	if(c == '-') ret = 62;
	if(c == '_') ret = 63;
	return(ret);
}

int get(int c) {
	int a = 1;
	for(int i = 0; i < 6; i++) {
		if((c >> i) & 1) {
			a *= 1;
			a %= mod;
		} else {
			a *= 3;
			a %= mod;
		}
	}
	return(a);
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

	string s;
	getline(cin, s);
	int ans = 1;
	for(int i = 0; i < (int)s.length(); i++) {
		ans = ans * 1ll * get(f(s[i])) % mod;
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