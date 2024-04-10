#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n;
int l[6][6], h[6][6], c[6][6], p[6];
int flow, cost, best_cost;
bool OK;
vector<vi> s[6][31];

void go(int i) {
	if (i + 1 < n) {
		vector <vi> & v = s[n - i - 1][p[i]];
		REP (kk, sz(v)) {
			bool ok = true;
			vi :: iterator u = v[kk].begin();
			for (int j = i + 1; j < n; ++j, ++u) {
				if (*u < l[i][j] || *u > h[i][j]) 
					ok = false;
				if (*u) {
					p[i] -= *u;
					p[j] += *u;
					cost += c[i][j] + (*u) * (*u);
				}
			}
			if (ok) go(i + 1);
			u = v[kk].begin();
			for (int j = i + 1; j < n; ++j, ++u) 
				if (*u) {
					p[i] += *u;
					p[j] -= *u;
					cost -= c[i][j] + (*u) * (*u);
				}
		}
	} else {
		OK = true;
		best_cost = max(cost, best_cost);
	}	 
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (kk, n * (n - 1) / 2) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		cin >> l[x][y] >> h[x][y] >> c[x][y];
	}
	for (int x = 0; x <= 25; ++x)
		s[1][x].pb(vi(1, x));
	for (int k = 2; k < 6; ++k) {
		REP (x, 26) REP (y, 26) if (x + y <= 25) {
			vector <vi> &v = s[k - 1][x], &w = s[k][x + y];
			REP (i, sz(v)) {
				vi t = v[i];
				t.pb(y);
				w.pb(t);
			}
		}
	}
	for (flow = 0; flow <= 25; ++flow) {
		p[0] = flow;
		go(0);
		if (OK) {
			printf("%d %d\n", flow, best_cost);
			return 0;
		}
		best_cost = 0;
	}
	puts("-1 -1");
	return 0;
}