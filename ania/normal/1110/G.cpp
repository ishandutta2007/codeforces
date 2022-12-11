#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

#define WHITE { printf("White\n"); return; }
#define DRAW { printf("Draw\n"); return; }

const int N = 500500;

int n;
vi g[N];
char col[N];

void test() {
	scanf("%d", &n);
	FOR(i,n) g[i].clear();
	FOR(i,n-1) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	scanf("%s", col);
	if (n < 3) {
		DRAW;
	}
	// 1 move win WWN
	FOR(i,n) if (col[i] == 'W') {
		FOR(j,SZ(g[i])) if (col[g[i][j]] == 'W') {
			WHITE;
		}
	}
	// 1 move win WNW
	FOR(i,n) if (col[i] == 'N') {
		int cnt = 0;
		FOR(j,SZ(g[i])) if (col[g[i][j]] == 'W') {
			cnt++;
		}
		if (cnt >= 2) {
			WHITE;
		}
	}
	if (n == 3) {
		DRAW;
	}
	// 2 moves win
	FOR(i,n) if (col[i] == 'W') {
		if (SZ(g[i]) > 1) { // NWNN
			WHITE;
		}
		int u = g[i][0];
		if (SZ(g[u]) > 2) { // triangle W
			WHITE;
		}
	}
	// 3 moves win star
	FOR(i,n) if (SZ(g[i]) >= 4) {
		WHITE;
	}
	// 3 moves win _ _|_ _
	FOR(i,n) if (SZ(g[i]) == 3) {
		int cnt = 0;
		FOR(j,SZ(g[i])) {
			if (SZ(g[g[i][j]]) > 1) cnt++;
		}
		if (cnt >= 2) {
			WHITE;
		}
	}
	int leaf = 0, leafW = 0;
	FOR(i,n) if (SZ(g[i]) == 1) {
		leaf++;
		if (col[i] == 'W') leafW++;
	}
	// path - - - - - -
	if (leaf == 2) {
		if (leafW == 2) {
			if (n % 2 == 1) {
				WHITE;
			}
		}
		DRAW;
	}
	// path > - - - - - <
	if (leaf == 4) {
		if (n % 2 == 1) {
			WHITE;
		}
		DRAW;
	}
	// path > - - - - - -
	if (leaf == 3) {
		if (leafW == 1) {
			if (n % 2 == 0) {
				WHITE;
			}
		}
		DRAW;
	}
	assert(0);
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}