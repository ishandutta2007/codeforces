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

map<int, vector<pair<int, pair<int, int> > > > ma;
map<int, vector<pair<int, pair<int, int> > > > :: iterator it;

vector<pair<int, int> > ans;

int deo[4 * maxn];

void add(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < pos || tl > pos) {
		return;
	}
	if(tl == tr) {
		deo[v] += val;
		return;
	}
	int tm = (tl + tr) >> 1;
	add(pos, val, v * 2 + 1, tl, tm);
	add(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = deo[v * 2 + 1] + deo[v * 2 + 2];
}

int getsum(int rg, int lf = 0, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < lf || tl > rg) {
		return 0;
	}
	if(lf <= tl && rg >= tr) {
		return deo[v];
	}
	int tm = (tl + tr) >> 1;
	return(getsum(rg, lf, v * 2 + 1, tl, tm) +
	getsum(rg, lf, v * 2 + 2, tm + 1, tr));
}

void rebuild() {
	for(int i = 0; i < 4 * maxn; i++) {
		deo[i] = 0;
	}
}

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
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
		int a, t, x;
		scanf("%d%d%d", &a, &t, &x);
		ma[x].pb(mp(a, mp(t, i)));
	}

	for(it = ma.begin(); it != ma.end(); it++) {
		vector<pair<int, pair<int, int> > > &vc = it -> sc;
		sort(vc.begin(), vc.end(), cmp);
		if(vc.size() > 500) {
			rebuild();
			for(int i = 0; i < (int)vc.size(); i++) {
				if(vc[i].fs == 1) {
					add(vc[i].sc.sc, 1);
				} else
				if(vc[i].fs == 2) {
					add(vc[i].sc.sc, -1);
				} else {
					ans.pb(mp(vc[i].sc.sc, getsum(vc[i].sc.sc)));
				}
			}
		} else {
			int sz = vc.size();
			int answ = 0;
			for(int i = 0; i < sz; i++) {
				if(vc[i].fs == 3) {
					answ = 0;
					for(int j = 0; j < i; j++) {
						if(vc[j].fs == 1 && vc[j].sc.sc < vc[i].sc.sc) {
							answ++;
						}
						if(vc[j].fs == 2 && vc[j].sc.sc < vc[i].sc.sc) {
							answ--;
						}
					}
					ans.pb(mp(vc[i].sc.sc, answ));
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); i++) {
		printf("%d\n", ans[i].sc);
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