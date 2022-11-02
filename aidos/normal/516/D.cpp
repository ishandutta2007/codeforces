#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

ll d1[500100];
ll d2[500100];
ll dx[500100];
int par[500100][25];
vector < pii > g[500100];
int n;
void dfs(int v, int p, ll w, ll *d){
	d[v] = w;
	forit(it, g[v]){
		if(it->f == p) continue;
		dfs(it->f, v, w + it->s, d);
		//d[v] = max(d[v], d[it->f] + it->s);
	}
}
void dfs2(int v, int p){
	par[v][0] = p;
	for(int i=1; i < 20&& par[v][i-1] > 0; i++){
		
		par[v][i] = par[par[v][i-1]][i-1];
	}
	forit(it, g[v]){
		if(it->f == p) continue;
		dfs2(it->f, v);
	}
}

ll maxi;

ll dfs3(int v, int p){
	ll w = 0;
	forit(it, g[v]){
		if(it->f == p) continue;
		w += dfs3(it->f, v);
	}
	maxi = max(w+d1[v], maxi);
	return w + d1[v] + d2[v];
}

void dfs4(int v, int p){
	forit(it, g[v]){
		if(it->f == p) continue;
		if(dx[it->f] < dx[v]) {
			//cout << -1 << endl;
			//exit(0);
//			assert(false);
		}
		dfs4(it->f, v);
	}
}

void up(int v, ll w){
	d1[v]++;
	for(int i = 18; i>=0; i--){
		if(par[v][i] > 0 && dx[par[v][i]] >= w) v = par[v][i];
	}
	d2[v]--;	
}

int getMaxDist(int v, ll *d){
	dfs(v, 0, 0, d);
	int u = 1;
	for(int i = 2; i<=n; i++){
		if(d[i] > d[u]) u = i;
	}
	return u;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
	
	cin >> n;

	for(int i = 1, x, y, w; i < n; i++){
		cin >> x >> y >> w;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	int u1 = getMaxDist(1, d1);
	int u2 = getMaxDist(u1, d1);
	int k = getMaxDist(u2, d2);
	int root = 1;
	for(int i = 1; i<=n; i++){
		dx[i] = max(d1[i], d2[i]);
		if(dx[root] > dx[i]) root = i;
	}
	memset(par, 0, sizeof par);
	
	dfs2(root, 0);
	
	dfs4(root, 0);
	/*cout << u1 << " "<< u2<< " " << root<< endl;
	for(int i = 1; i<=n; i++){
		cout << i << " " << d[i] << endl;

	} */
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll L;
		cin >> L;
		for(int j = 1; j <= n; j++){
			d1[j] = 0;
			d2[j] = 0;
		}
		for(int j = 1; j <= n; j++){
			up(j, dx[j] - L);
		}
		maxi = 0;
		dfs3(root, 0);
		cout << maxi << endl;
		
	}








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}