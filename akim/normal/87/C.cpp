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

int deo[4 * maxn], g[maxn];

void add(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < pos || tl > pos) {
		return;
	}
	if(tl == tr) {
		deo[v] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	add(pos, val, v * 2 + 1, tl, tm);
	add(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = min(deo[v * 2 + 1], deo[v * 2 + 2]);
}

int downtomin(int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl == tr) {
		return(tl);
	}
	int tm = (tl + tr) >> 1;
	if(deo[v * 2 + 1] < val) {
		return(downtomin(val, v * 2 + 1, tl, tm));
	} else {
		return(downtomin(val, v * 2 + 2, tm + 1, tr));
	}
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

	for(int i = 2; i < maxn; i++) {
		for(int j = 2; ((j * (j + 1)) >> 1) <= i; j++) {
			int k = ((j * (j + 1)) >> 1);
			if((i - k) % j != 0) continue;
			int l = (i -  k) / j;
			add(g[l + j] ^ (l ? g[l] : 0), i);
		}
		g[i] = g[i - 1] ^ downtomin(i);
	}

	int n;
	scanf("%d", &n);
	int gr = g[n] ^ ((n - 1) ? g[n - 1] : 0);
	if(gr) {
		for(int j = 2; ((j * (j + 1)) >> 1) <= n; j++) {
			int k = ((j * (j + 1)) >> 1);
			if((n - k) % j != 0) continue;
			int l = (n -  k) / j;
			if((g[l + j] ^ (l ? g[l] : 0)) == 0) {
				printf("%d", j);
				break;
			}
		}

	} else {
		printf("-1\n");
	}

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