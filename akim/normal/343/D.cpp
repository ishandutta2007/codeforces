#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 500100;

int n;
int deo[4 * maxn];
bool bnewval[4 * maxn];
int inewval[4 * maxn];
vector<int> rb[maxn];
vector<int> ts;
int l[maxn], r[maxn];
bool pm[maxn];
int predok[maxn];

void topsort(int u) {
	l[u] = ts.size();
	pm[u] = 1;
	ts.pb(u);
	for(int i = 0; i < (int)rb[u].size(); i++) if(!pm[rb[u][i]]) {
		predok[rb[u][i]] = l[u];
		topsort(rb[u][i]);
	}
	r[u] = ts.size() - 1;
}

void upd(int *deo, int lf, int rg, int val, int v = 0, int tl = 0, int tr = n - 1) {
	if(lf > rg) {
		return;
	}
	if(lf == tl && rg == tr) {
		bnewval[v] = 1;
		inewval[v] = val;
		return;
	}
	if(bnewval[v] == 1) {
		bnewval[v] = 0;
		bnewval[v * 2 + 1] = 1;
		inewval[v * 2 + 1] = inewval[v];
		bnewval[v * 2 + 2] = 1;
		inewval[v * 2 + 2] = inewval[v];
	}
	int tm = (tl + tr) >> 1;
	upd(deo, lf, min(tm, rg), val, v * 2 + 1, tl, tm);
	upd(deo, max(tm + 1, lf), rg, val, v * 2 + 2, tm + 1, tr);
	inewval[v] = min(inewval[v * 2 + 1], inewval[v * 2 + 2]);
}

int get(int *deo, int lf, int rg, int v = 0, int tl = 0, int tr = n - 1) {
	if(lf > rg) {
		return(1);
	}
	if(lf == tl && rg == tr) {
		return(inewval[v]);
	}
	if(bnewval[v] == 1) {
		bnewval[v] = 0;
		bnewval[v * 2 + 1] = 1;
		inewval[v * 2 + 1] = inewval[v];
		bnewval[v * 2 + 2] = 1;
		inewval[v * 2 + 2] = inewval[v];
	}
	int tm = (tl + tr) >> 1;
	int c1 = get(deo, lf, min(tm, rg), v * 2 + 1, tl, tm);
	int c2 = get(deo, max(tm + 1, lf), rg, v * 2 + 2, tm + 1, tr);
	inewval[v] = min(inewval[v * 2 + 1], inewval[v * 2 + 2]);
	return (min(c1, c2));
}

void setval(int *deo, int u, int v = 0, int tl = 0, int tr = n - 1) {
	if(tl == tr) {
		bnewval[v] = 1;
		inewval[v] = 0;
		return;
	}
	if(bnewval[v] == 1) {
		bnewval[v] = 0;
		bnewval[v * 2 + 1] = 1;
		inewval[v * 2 + 1] = inewval[v];
		bnewval[v * 2 + 2] = 1;
		inewval[v * 2 + 2] = inewval[v];
	}
	int tm = (tl + tr) >> 1;
	if(tm >= u) {
		setval(deo, u, v * 2 + 1, tl, tm);
	} else {
		setval(deo, u, v * 2 + 2, tm + 1, tr);
	}
	inewval[v] = min(inewval[v * 2 + 1], inewval[v * 2 + 2]);
}

void out(int *deo, int v = 0, int tl = 0, int tr = n - 1) {
	if(tl == tr) {
//		cout << tl << " " << tr << " " << inewval[v] << "\n";
	} else {
		if(bnewval[v] == 1) {
			bnewval[v] = 0;
			bnewval[v * 2 + 1] = 1;
			inewval[v * 2 + 1] = inewval[v];
			bnewval[v * 2 + 2] = 1;
			inewval[v * 2 + 2] = inewval[v];
		}
		int tm = (tl + tr) >> 1;
		out(deo, v * 2 + 1, tl, tm);
		out(deo, v * 2 + 2, tm + 1, tr);
		inewval[v] = min(inewval[v * 2 + 1], inewval[v * 2 + 2]);
//		cout << tl << " " << tr << " " << inewval[v] << "\n";
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	topsort(0);

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++) {
		int c, v;
		scanf("%d%d", &c, &v); v--;
		if(c == 1) {
			if(get(deo, l[v], r[v]) == 0) {
				upd(deo, l[v], r[v], 1);
				if(v > 0) setval(deo, predok[v]);
			} else {
				upd(deo, l[v], r[v], 1);
			}
		}
		if(c == 2) {
			setval(deo, l[v]);
		}
		if(c == 3) {
			printf("%d\n", get(deo, l[v], r[v]));
		}
	}

	out(deo);

	return(0);
}

// by Kim Andrey