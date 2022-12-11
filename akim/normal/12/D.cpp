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
const int maxn = 500100;

pair<int, pair<int, int> > a[maxn];
int deo[4 * maxn];
void add(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > pos || tr < pos) {
		return;
	}
	if(tl == tr) {
		deo[v] = max(val, deo[v]);
		return;
	}
	int tm = (tl + tr) >> 1;
	add(pos, val, v * 2 + 1, tl, tm);
	add(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
}

int getmax(int lf, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || tr < tl) {
		return(0);
	}
	if(tl >= lf) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(max(getmax(lf, v * 2 + 1, tl, tm), getmax(lf, v * 2 + 2, tm + 1, tr)));
}


bool cmp2(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return(a.sc.fs < b.sc.fs);
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
		scanf("%d", &a[i].fs);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].sc.fs);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].sc.sc);
	}
	sort(&a[0], &a[n], cmp2);
	int lst = -1, id = -1;
	for(int i = 0; i < n; i++) {
		if(a[i].sc.fs != lst) {
			lst = a[i].sc.fs;
			id++;
		}
		a[i].sc.fs = id;
	}

	sort(&a[0], &a[n], greater<pair<int, pair<int, int> > >());

	int ans = 0;
	for(int i = 0, f = 0; i < n; i++) {
		while(f < n && a[f].fs > a[i].fs) {
			add(a[f].sc.fs, a[f].sc.sc);
			f++;
		}
		if(getmax(a[i].sc.fs + 1) > a[i].sc.sc) {
			ans++;
		}
	}

	cout << ans;

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