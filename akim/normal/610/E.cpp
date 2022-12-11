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
const int maxn = 200100;

int n, m, k;
int deo[11][11][4 * maxn];
int lef[4 * maxn], rig[4 * maxn];
bool ud[4 * maxn];
vector<int> vc;
int str[maxn];
string s;


void build(int v = 0, int tl = 0, int tr = n - 1) {
	if(tl == tr) {
		lef[v] = s[tl] - 'a';
		rig[v] = s[tl] - 'a';
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			deo[i][j][v] = deo[i][j][v * 2 + 1] + deo[i][j][v * 2 + 2];
		}
	}
	deo[rig[v * 2 + 1]][lef[v * 2 + 2]][v]++;
	lef[v] = lef[v * 2 + 1];
	rig[v] = rig[v * 2 + 2];
}

void upd(int v = 0, int tl = 0, int tr = n - 1) {
	if(ud[v]) {
		int tm = (tl + tr) >> 1;
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) {
				deo[i][j][v * 2 + 1] = (tm - tl) * (deo[i][j][v] != 0);
				deo[i][j][v * 2 + 2] = (tr - (tm + 1)) * (deo[i][j][v] != 0);
			}
		}
		ud[v] = 0;
		ud[v * 2 + 1] = 1;
		ud[v * 2 + 2] = 1;
		lef[v * 2 + 1] = lef[v];
		rig[v * 2 + 1] = rig[v];
		lef[v * 2 + 2] = lef[v];
		rig[v * 2 + 2] = rig[v];
	}
}

void update(int lf, int rg, int val, int v = 0, int tl = 0, int tr = n - 1) {
	if(tr < lf || tl > rg) {
		return;
	}
	if(lf <= tl && tr <= rg) {
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) {
				deo[i][j][v] = 0;
			}
		}
		deo[val][val][v] = (tr - tl);
		lef[v] = val;
		rig[v] = val;
		ud[v] = 1;
		return;
	}
	upd(v, tl, tr);
	int tm = (tl + tr) >> 1;
	update(lf, rg, val, v * 2 + 1, tl, tm);
	update(lf, rg, val, v * 2 + 2, tm + 1, tr);
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			deo[i][j][v] = deo[i][j][v * 2 + 1] + deo[i][j][v * 2 + 2];
		}
	}
	deo[rig[v * 2 + 1]][lef[v * 2 + 2]][v]++;
	lef[v] = lef[v * 2 + 1];
	rig[v] = rig[v * 2 + 2];
}

int getsum(int i, int j) {
	return(deo[i][j][0]);
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

	scanf("%d%d%d\n", &n, &m, &k);
	getline(cin, s);
	build();

	vc.resize(k);

	for(int p = 0; p < m; ++p) {
		int tp;
		scanf("%d", &tp);
		if(tp == 1) {
			int lf, rg;
			char c;
			scanf("%d%d%*c%c", &lf, &rg, &c);
			lf--, rg--;
			update(lf, rg, c - 'a');
		} else {
			getchar();
			for(int i = 0; i < k; ++i) {
				vc[i] = (getchar() - 'a');
			}
			int ans = 1;
			for(int i = 0; i < k; ++i) {
				for(int j = 0; j <= i; ++j) {
					ans += getsum(vc[i], vc[j]);
				}
			}
			printf("%d\n", ans);
		}
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