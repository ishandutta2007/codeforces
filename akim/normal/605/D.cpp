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

int a[maxn], b[maxn], c[maxn], d[maxn];
int id[maxn], rv[maxn];
bool pm[maxn];
int len[maxn], prevuse[maxn];

pair<int, int> deo[4 * maxn];

bool cmp(int c, int d) {
	return(a[c] == a[d] ? b[c] < b[d] : a[c] < a[d]);
}
map<int, int> fr;

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > tr) {
		return;
	}
	if(tl == tr) {
		deo[v] = mp(b[id[tl]], tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	deo[v] = min(deo[v * 2 + 1], deo[v * 2 + 2]);
}

void remove(int pos, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > tr || tl > pos || tr < pos) {
		return;
	}
	if(tl == tr) {
		deo[v] = mp(mod, pos);
		return;
	}
	int tm = (tl + tr) >> 1;
	remove(pos, v * 2 + 1, tl, tm);
	remove(pos, v * 2 + 2, tm + 1, tr);
	deo[v] = min(deo[v * 2 + 1], deo[v * 2 + 2]);
}

pair<int, int> getmin(int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	int lf = 0;
	if(tl > tr || tl > rg || tr < lf) {
		return(mp(mod, mod));
	}
	if(tl >= lf && tr <= rg) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(min(getmin(rg, v * 2 + 1, tl, tm), getmin(rg, v * 2 + 2, tm + 1, tr)));
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
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		id[i] = i;
	}
	sort(&id[0], &id[n], cmp);
	for(int i = 0; i < n; i++) {
		int &j = id[i];
		rv[j] = i;
		fr[a[j]] = i;
	}

	build();
	vector<pair<int, pair<int, pair<int, int> > > > vc;
	vc.pb(mp(0, mp(-1, mp(0, 0))));

	for(int i = 0; i < (int)vc.size(); i++) {
		int l = vc[i].fs, idx = vc[i].sc.fs, x = vc[i].sc.sc.fs, y = vc[i].sc.sc.sc;
		pair<int, int> pa;
		while(fr.upper_bound(x) != fr.begin() && (pa = getmin((--fr.upper_bound(x)) -> sc)).fs <= y) {
			pm[id[pa.sc]] = 1;
			prevuse[id[pa.sc]] = idx;
			len[id[pa.sc]] = l + 1;
			vc.pb(mp(l + 1, mp(id[pa.sc], mp(c[id[pa.sc]], d[id[pa.sc]]))));
			remove(pa.sc);
		}
	}

	if(!pm[n - 1]) {
		printf("-1\n");
		return(0);
	}
	printf("%d\n", len[n - 1]);
	vector<int> ans;
	for(int i = n - 1; i != -1; i = prevuse[i]) {
		ans.pb(i);
	}

	for(int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i] + 1);
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