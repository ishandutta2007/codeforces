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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

pair<int, int> dp[500100];
int x[500100];
int pr[500100];
int o1[500100], o2[500100];

map<int, int> ma;
vector<int> vc;

void rek(int u) {
	if(dp[u].fs == 0) {return;}
	rek(dp[u].sc);
	printf("%d %d %d %d ", o1[u], o2[u], o1[u], o2[u]);
}

int deo[4 * 500100], n;


int fmax(int *deo, int p,  int v = 0, int tl = 0, int tr = n - 1) {
	if(tl == tr) {
		return(deo[v]);
	} else {
		int tm = (tl + tr) / 2;
		if(p <= tm) {
			return(max(deo[v], fmax(deo, p, v * 2 + 1, tl, tm)));
		} else {
			return(max(deo[v], fmax(deo, p, v * 2 + 2, tm + 1, tr)));
		}
	}
}

void upd(int *deo, int l, int r, int x, int v = 0, int tl = 0, int tr = n - 1) {
	if(v > mod) {exit(0);}
	if(l > r) {
		return;
	}
	if(tl == l && tr == r) {
		deo[v] = max(deo[v], x);
	} else {
		int tm = (tl + tr) / 2;
		upd(deo, l, min(tm, r), x, v * 2 + 1, tl, tm);
		upd(deo, max(l, tm + 1), r, x, v * 2 + 2, tm + 1, tr);
	}
}


int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	scanf("%d", &n); n++;
	dp[0] = mp(0, -1);
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		o1[i] = o1[i - 1], o2[i] = o2[i - 1];
		scanf("%d", &x[i]);
		if(ma.count(x[i])) {
			pr[i] = ma[x[i]];
			int f = vc.size() - 1;
			bool found = 0;
			int c1, c2;

			int pos = fmax(deo, pr[i]);
			if(pos > 0 && x[pos] != x[i]) {
				int p = pos - 1;
				pair<int, int> o = dp[p];
				o.fs++; o.sc = p;
				if(o.fs > dp[i].fs) {
					o1[i] = x[pos], o2[i] = x[i];
					dp[i] = o;
				}
			}
			upd(deo, pr[i], i-1, pr[i]);

			found = 0;
			if(pr[pr[i]] != -1 && pr[pr[pr[i]]] != -1) {
				c1 = x[i];
				c2 = x[i];
				found = 1;
				f = pr[pr[i]];
			}

			if(found) {
				int p = pr[f] - 1;
				pair<int, int> o = dp[p];
				o.fs++; o.sc = p;
				if(o.fs > dp[i].fs) {
					o1[i] = c1, o2[i] = c2;
					dp[i] = o;
				}
			}

			vc.pb(i);
		} else {
			pr[i] = -1;
		}
		ma[x[i]] = i;
	}
	printf("%d\n", 4 * dp[n - 1].fs);
	rek(n - 1);



	return(0);
}

// by Kim Andrey