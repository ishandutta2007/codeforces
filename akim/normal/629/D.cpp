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

ll deo[4 * maxn], dp[maxn];
ll v[maxn];
int id[maxn];

ll getmax(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || tl > rg) {
		return(0);
	}
	if(lf <= tl && tr <= rg) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(max(getmax(lf, rg, v * 2 + 1, tl, tm), getmax(lf, rg, v * 2 + 2, tm + 1, tr)));
}

void update(int pos, ll val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(pos < tl || pos > tr) {
		return;
	}
	if(tl == tr) {
		deo[v] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(pos, val, v * 2 + 1, tl, tm);
	update(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
	return;
}

bool cmp(int a, int b) {
	return(mp(v[a], -a) < mp(v[b], -b));
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
		ll r, h;
		scanf("%lld%lld", &r, &h);
		v[i] = r * r * h;
		id[i] = i;
	}
	sort(&id[0], &id[n], cmp);

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, dp[id[i]] = getmax(0, id[i]) + v[id[i]]);
		update(id[i], dp[id[i]]);
	}

	printf("%.10lf", ans * pi);

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