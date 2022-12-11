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

char c[55][55];

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

	int n;
	scanf("%d", &n);
	int c4 = 0, mxi = -mod, mni = mod, mxj = -mod, mnj = mod;

	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int j = 0; j < n; j++) {
			scanf("%c", &c[i][j]);
			if(c[i][j] == '4') {
				c4++;
				mxi = max(mxi, i);
				mni = min(mni, i);
				mxj = max(mxj, j);
				mnj = min(mnj, j);
			}
		}
	}
	bool ok = 1;
	if(c4 == 0 || c4 != (mxi - mni + 1) * (mxj- mnj + 1)) {
		ok = 0;
	}
	if(ok)
	for(int i = mni, j = mnj - 1; i <= mxi; i++) {
		if(j >= 0 && c[i][j] != '2') {
			ok = 0;
		}
	}
	if(ok)
	for(int i = mni, j = mxj + 1; i <= mxi; i++) {
		if(j < n && c[i][j] != '2') {
			ok = 0;
		}
	}
	if(ok)
	for(int j = mnj, i = mni - 1; j <= mxj; j++) {
		if(i >= 0 && c[i][j] != '2') {
			ok = 0;
		}
	}
	if(ok)
	for(int j = mnj, i = mxi + 1; j <= mxj; j++) {
		if(i < n && c[i][j] != '2') {
			ok = 0;
		}
	}
	if(ok)
	if(mni - 1 >= 0 && mnj - 1 >= 0 && c[mni - 1][mnj - 1] != '1') {
		ok = 0;
	}
	if(ok)
	if(mni - 1 >= 0 && mxj + 1 < n && c[mni - 1][mxj + 1] != '1') {
		ok = 0;
	}
	if(ok)
	if(mxi + 1 < n && mnj - 1 >= 0 && c[mxi + 1][mnj - 1] != '1') {
		ok = 0;
	}
	if(ok)
	if(mxi + 1 < n && mxj + 1 < n && c[mxi + 1][mxj + 1] != '1') {
		ok = 0;
	}

	mni--, mnj--, mxi++, mxj++;
	if(ok)
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(mni <= i && i <= mxi && mnj <= j && j <= mxj) {
				continue;
			}
			if(c[i][j] != '0') {
				ok = 0;
			}
		}
	}

	if(ok) {
		printf("Yes\n");
	} else {
		printf("No\n");
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