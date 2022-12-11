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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

vector<int> x[maxn];
int deomx[maxn * 4], deomn[maxn * 4];
pair<int, int> lad[2 * maxn];
pair<pair<pair<int, int>, pair<int, int> >, int> zap[2 * maxn];
bool ans[2 * maxn];
int n, m;

void build(int *a, int v = 0, int tl = 0, int tr = m) {
 	if(tl == tr) {
 		deomx[v] = a[tl];
 		deomn[v] = a[tl];
 		return;
 	}
 	int tm = (tl + tr) >> 1;
 	build(a, v * 2 + 1, tl, tm);
 	build(a, v * 2 + 2, tm + 1, tr);
 	deomx[v] = max(deomx[v * 2 + 1], deomx[v * 2 + 2]);
 	deomn[v] = min(deomn[v * 2 + 1], deomn[v * 2 + 2]);
}

void change(int pos, int val, int v = 0, int tl = 0, int tr = m) {
 	if(tl == tr) {
 		deomx[v] = val;
 		deomn[v] = val;
 		return;
 	}
 	int tm = (tl + tr) >> 1;
 	if(pos <= tm) {
 		change(pos, val, v * 2 + 1, tl, tm);
 	} else {
 		change(pos, val, v * 2 + 2, tm + 1, tr);
 	}
 	deomx[v] = max(deomx[v * 2 + 1], deomx[v * 2 + 2]);
 	deomn[v] = min(deomn[v * 2 + 1], deomn[v * 2 + 2]);
}

pair<int, int> get(int lf, int rg, int v = 0, int tl = 0, int tr = m) {
//	cout << lf << " " << rg << " " << tl << " " << tr << endl;
//	system("pause");
	if(lf > rg) {
		return(mp(-mod, mod));
	}
	if(lf == tl && rg == tr) {
		return(mp(deomx[v], deomn[v]));
	}
	int tm = (tl + tr) >> 1;
	pair<int, int> p1 = get(lf, min(tm, rg), v * 2 + 1, tl, tm);
	pair<int, int> p2 = get(max(lf, tm + 1), rg, v * 2 + 2, tm + 1, tr);
	return(mp(max(p1.fs, p2.fs), min(p1.sc, p2.sc)));
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

	int k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &lad[i].fs, &lad[i].sc);
	}
	for(int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &zap[i].fs.fs.fs, &zap[i].fs.fs.sc, &zap[i].fs.sc.fs, &zap[i].fs.sc.sc);
		zap[i].sc = i;
	}


	sort(&lad[0], &lad[k]);
	sort(&zap[0], &zap[q]);
	for(int i = k - 1; i >= 0; i--) {
		x[lad[i].sc].pb(lad[i].fs);
	}
	for(int i = 1; i <= m; i++) {
		if(!x[i].empty()) {
			change(i, x[i].back());
			x[i].ppb();
		}
	}
	int f = 0, g = 0;
	for(int i = 1; i <= n; i++) {
		while(g < q && zap[g].fs.fs.fs == i) {
			int x1 = zap[g].fs.fs.fs, y1 = zap[g].fs.fs.sc;
			int x2 = zap[g].fs.sc.fs, y2 = zap[g].fs.sc.sc;
			int nz = zap[g].sc;
			pair<int, int> p = get(y1, y2);
			if(p.sc != 0 && p.fs <= x2) {
				ans[nz] = 1;
			}
			g++;
		}
		while(f < k && lad[f].fs == i) {
			int pos = lad[f].sc;
			if(x[pos].empty()) {
				change(pos, 0);
			} else {
				change(pos, x[pos].back());
				x[pos].ppb();
			}
			f++;
		}
	}


	swap(n, m);
	for(int i = 0; i < k; i++) {
		swap(lad[i].fs, lad[i].sc);
	}
	for(int i = 0; i < q; i++) {
		swap(zap[i].fs.fs.fs, zap[i].fs.fs.sc);
		swap(zap[i].fs.sc.fs, zap[i].fs.sc.sc);
	}


//	for(int i = 0; i < q; i++) {
//		if(ans[i]) {
//			cout << "YES\n";
//		} else {
//			cout << "NO\n";
//		}
//	}


	sort(&lad[0], &lad[k]);
	sort(&zap[0], &zap[q]);
	for(int i = k - 1; i >= 0; i--) {
		x[lad[i].sc].pb(lad[i].fs);
	}
	for(int i = 1; i <= m; i++) {
		if(!x[i].empty()) {
			change(i, x[i].back());
			x[i].ppb();
		}
	}
	f = 0, g = 0;
	for(int i = 1; i <= n; i++) {
		while(g < q && zap[g].fs.fs.fs == i) {
			int x1 = zap[g].fs.fs.fs, y1 = zap[g].fs.fs.sc;
			int x2 = zap[g].fs.sc.fs, y2 = zap[g].fs.sc.sc;
			int nz = zap[g].sc;
			pair<int, int> p = get(y1, y2);
			if(p.sc != 0 && p.fs <= x2) {
				ans[nz] = 1;
			}
			g++;
		}
		while(f < k && lad[f].fs == i) {
			int pos = lad[f].sc;
			if(x[pos].empty()) {
				change(pos, 0);
			} else {
				change(pos, x[pos].back());
				x[pos].ppb();
			}
			f++;
		}
	}

	for(int i = 0; i < q; i++) {
		if(ans[i]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return(0);
}

// by Kim Andrey