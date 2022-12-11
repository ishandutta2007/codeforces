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
const int maxn = 2000100;

int a[maxn];
int b[maxn];
ll ans[2][30];
bool cur[30];

//c*(c-1)/2

void getcnt(int lv, int lf, int rg) {
	int md = (lf + rg) >> 1;
	if(lf + 1 != rg) {
		getcnt(lv - 1, lf, md);
		getcnt(lv - 1, md, rg);
	} else return;
	ll cnt = 0, cnt1 = 0;
	int i = lf, j = md, id = lf, eq = 0, val = -1;
	while(i < md && j < rg) {
		if(a[i] <= a[j]) {
			if(a[i] == val) eq++; else eq = 1, val = a[i];
			cnt += j - md;
			b[id++] = a[i++];
		} else {
			cnt1 += i - lf - eq * (a[j] == val);
			b[id++] = a[j++];
		}
	}
	while(i < md) {
		cnt += j - md;
		b[id++] = a[i++];
	}
	while(j < rg) {
		cnt1 += i - lf - eq * (a[j] == val);
		b[id++] = a[j++];
	}
	for(int i = lf; i < rg; i++) {
		a[i] = b[i];
	}
	ans[0][lv] += cnt;
	ans[1][lv] += cnt1;
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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < (1 << n); i++) {
		scanf("%d", &a[i]);
	}
	getcnt(n, 0, (1 << n));
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		ll ret = 0;
		for(int j = 0; j <= n; j++) {
			if(j <= x) cur[j] = !cur[j];
			ret += ans[cur[j]][j];
		}
		printf("%lld\n", ret);
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