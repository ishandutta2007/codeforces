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

vector<int> vc, rb[100100];
int x[100100], z[100100], del[2000200], prin[2000200];
bool pm[100100];
int t = 0, tin[100100];

void dfs(int u) {
	pm[u] = 1;
	tin[u] = ++t;
	z[u] = -1;
	int xx = x[u];
	vector<pair<int,int> > prv;
	while(xx > 1) {
		if(prin[del[xx]] > 0) {
			if(z[u] == -1 || (prin[del[xx]] != u && tin[z[u]] < tin[prin[del[xx]]])) {
				z[u] = prin[del[xx]];
			}
		}
		prv.pb(mp(del[xx], prin[del[xx]]));
		prin[del[xx]] = u;
		int k = del[xx];
		while(xx % k == 0) {xx /= k;}
	}

	for(int i = 0; i < rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i]);
		}
	}

	for(int i = ((int)prv.size()) - 1; i >= 0; i--) {
		prin[prv[i].fs] = prv[i].sc;
	}

	pm[u] = 0; t--;
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	for(int i = 2; i < 2000200; i++) {
		if(del[i] == 0) {
			for(int f = i; f < 2000200; f += i) {
				del[f] = i;
			}
		}
	}

	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {scanf("%d", &x[i]);}

	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		rb[u].pb(v);
		rb[v].pb(u);
	}

	dfs(1);

	for(; m > 0; m--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int u; scanf("%d", &u);
			printf("%d\n", z[u]);
		} else {
			int u, c; scanf("%d%d", &u, &c);
			x[u] = c;
			dfs(1);
		}
	}
	
	
	return(0);
}

// by Kim Andrey