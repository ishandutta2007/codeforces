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
const int maxn = 1000100;

int fv[maxn], ans[maxn], st[maxn], sz;
vector<pair<pair<int, int>, int> > zp;

void add(int u, int val) {
	for(; u < maxn; u = u | (u + 1)) {
		fv[u] += val;
	}
}

int get(int u) {
	int ret = 0;
	for(; u >= 0; u = u & (u + 1), u--) {
		ret += fv[u];
	}
	return(ret);
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
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
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		zp.pb(mp(mp(v, u), i));
	}

	sort(zp.begin(), zp.end());

	sz = 0;
	int cur = 0;
	for(int i = 0; i < m; i++) {
		int r = zp[i].fs.fs, l = zp[i].fs.sc, id = zp[i].sc;
		while(cur <= r) {
			if(s[cur] == '(') {
				st[sz++] = cur;
			} else {
				if(sz) add(st[--sz], 1);
			}
			cur++;
		}
		ans[id] = get(r) - get(l - 1);
	}

	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i] * 2);
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