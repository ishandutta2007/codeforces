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

int d[100100][32];
int mr[100100][32];
int otv[100100];
int tin[100100], tout[100100], t;
int zp, o;
pair<int, int> z[100100];
vector<pair<int, int> > rb[100100];
vector<pair<pair<int, int>, int> > zap[100100];
bool nh[100100];

void dfs(int u) {
	tin[u] = t++;
	for(int i = 0; i < 31; i++) {
		d[u][i + 1] = d[d[u][i]][i];
		mr[u][i + 1] = max(mr[u][i], mr[d[u][i]][i]);
	}
	for(int i = 0; i < (int)rb[u].size(); i++) {
		d[rb[u][i].fs][0] = u;
		mr[rb[u][i].fs][0] = rb[u][i].sc;
		dfs(rb[u][i].fs);
	}
	tout[u] = t++;
}

void check(int u) {
	for(int i = 0; i < (int)zap[u].size(); i++) {
		int v = zap[u][i].fs.fs, no = zap[u][i].fs.sc, tm = zap[u][i].sc, mw = -1;
		bool ok = 1;
		if(tin[u] <= tin[v] && tout[v] <= tout[u]){
			for(int i = 31; i >= 0; i--) {
				if(tin[u] <= tin[d[v][i]] && tout[d[v][i]] <= tout[u]) {
					mw = max(mw, mr[v][i]);
					v = d[v][i];
				}
			}
			if(mw > tm) {ok = 0;}
		} else {
			ok = 0;
		}
		otv[no] = ok;
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n, m; scanf("%d%d", &n, &m);
	for(int q = 0; q < m; q++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int a, b; scanf("%d%d", &a, &b);
			rb[b].pb(mp(a, q));
			nh[a] = 1;
		}
		if(t == 2) {
			int a; scanf("%d", &a);
			z[++zp] = mp(a, q);
		}
		if(t == 3) {
			int a, b; scanf("%d%d", &a, &b);
			zap[a].pb(mp(mp(z[b].fs, o++), z[b].sc));
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!nh[i]) {
			for(int f = 0; f < 32; f++) {d[i][f] = i;}
			dfs(i);
		}
	}
	for(int i = 1; i <= n; i++) check(i);

	for(int i = 0; i < o; i++) {
		if(otv[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return(0);
}

// by Kim Andrey