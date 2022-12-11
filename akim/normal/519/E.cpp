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

vector<int> rb[maxn];
bool used[maxn];
int lca[maxn][20];
int tin[maxn], tout[maxn], t;
int cnt[maxn];

void dfs(int u) {
	used[u] = 1;
	tin[u] = t++;
	cnt[u] = 1;
	for(int i = 1; i < 20; i++) {
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	}
	for(int i = 0; i < (int)rb[u].size(); i++) {
		if(!used[rb[u][i]]) {
			lca[rb[u][i]][0] = u;
			dfs(rb[u][i]);
			cnt[u] += cnt[rb[u][i]];
		}
	}
	tout[u] = t++;
}

int getlca(int u, int v) {
	if(tin[u] > tin[v]) {
		swap(u, v);
	}
	if(tout[u] > tout[v]) {
		int d1 = 1;
		int g = v;
		for(int i = 19; i >= 0; i--) {
			if(!(tin[lca[g][i]] <= tin[u] && tout[lca[g][i]] >= tout[u])) {
				g = lca[g][i];
				d1 += 1 << i;
			}
		}
		if((d1 & 1) == 1) {
			return(0);
		}
		d1 >>= 1;
		d1--;
		g = v;
		for(int i = 19; i >= 0; i--) {
			if((1 << i) <= d1) {
				g = lca[g][i];
				d1 -= 1 << i;
			}
		}
		return(cnt[lca[g][0]] - cnt[g]);
	} else {
		int d1 = 1, d2 = 1;
		int g = u;
		for(int i = 19; i >= 0; i--) {
			if(!(tin[lca[g][i]] < tin[v] && tout[lca[g][i]] > tout[v])) {
				g = lca[g][i];
				d1 += 1 << i;
			}
		}
		int g1 = g;
		g = v;
		for(int i = 19; i >= 0; i--) {
			if(!(tin[lca[g][i]] < tin[u] && tout[lca[g][i]] > tout[u])) {
				g = lca[g][i];
				d2 += 1 << i;
			}
		}
		int g2 = g;
		if(((d1 + d2) & 1) == 1) {
			return(0);
		}
		if(d1 == d2) {
			return(cnt[0] - cnt[g1] - cnt[g2]);
		}
		if(d1 > d2) {
			d1 = d1 + d2;
			d1 >>= 1;
			d1--;
			g = u;
			for(int i = 19; i >= 0; i--) {
				if((1 << i) <= d1) {
					g = lca[g][i];
					d1 -= 1 << i;
				}
			}
			return(cnt[lca[g][0]] - cnt[g]);
		} else {
			d1 = d1 + d2;
			d1 >>= 1;
			d1--;
			g = v;
			for(int i = 19; i >= 0; i--) {
				if((1 << i) <= d1) {
					g = lca[g][i];
					d1 -= 1 << i;
				}
			}
			return(cnt[lca[g][0]] - cnt[g]);
		}
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

	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	lca[0][0] = 0;
	dfs(0);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		int ans = u == v ? n : getlca(u, v);
		printf("%d\n", ans);
	}

	return(0);
}

// by Kim Andrey