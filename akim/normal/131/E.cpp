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

struct node {
	int x, y, id;
};
bool cmp1(node a, node b) {
	return(mp(a.x, a.y) < mp(b.x, b.y));
}
bool cmp2(node a, node b) {
	return(mp(a.y, a.x) < mp(b.y, b.x));
}
bool cmp3(node a, node b) {
	return(mp(a.x + a.y, a.x) < mp(b.x + b.y, b.x));
}
bool cmp4(node a, node b) {
	return(mp(a.x - a.y, a.x) < mp(b.x - b.y, b.x));
}
node f[maxn];
int cnt[maxn];
int ans[9];

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
	scanf("%*d%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &f[i].x, &f[i].y);
		f[i].id = i;
	}

	sort(&f[0], &f[n], cmp1);
	for(int i = 1; i < n; i++)
		if(f[i].x == f[i - 1].x)
			cnt[f[i].id]++;
	reverse(&f[0], &f[n]);
	for(int i = 1; i < n; i++)
		if(f[i].x == f[i - 1].x)
			cnt[f[i].id]++;
	sort(&f[0], &f[n], cmp2);
	for(int i = 1; i < n; i++)
			if(f[i].y == f[i - 1].y)
				cnt[f[i].id]++;
	reverse(&f[0], &f[n]);
	for(int i = 1; i < n; i++)
				if(f[i].y == f[i - 1].y)
					cnt[f[i].id]++;
	sort(&f[0], &f[n], cmp3);
	for(int i = 1; i < n; i++)
		if(f[i].x + f[i].y == f[i - 1].x + f[i - 1].y)
			cnt[f[i].id]++;
	reverse(&f[0], &f[n]);
	for(int i = 1; i < n; i++)
		if(f[i].x + f[i].y == f[i - 1].x + f[i - 1].y)
			cnt[f[i].id]++;
	sort(&f[0], &f[n], cmp4);
	for(int i = 1; i < n; i++)
		if(f[i].x - f[i].y == f[i - 1].x - f[i - 1].y)
			cnt[f[i].id]++;
	reverse(&f[0], &f[n]);
	for(int i = 1; i < n; i++)
		if(f[i].x - f[i].y == f[i - 1].x - f[i - 1].y)
			cnt[f[i].id]++;
	for(int i = 0; i < n; i++) {
		ans[cnt[i]]++;
	}

	for(int i = 0; i <= 8; i++) {
		printf("%d ", ans[i]);
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