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
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int w[200200];
int a[200200];
int b[200200];
int c[200200];
int p[22][200200];
int up[22][200200];
int per[200200];
int m;
int n;
int com[200200];

bool ok[200200];

vector<int> g[200200];

int cmp(int i, int j){
	return w[i] < w[j];
}

int get(int v){
	if(com[v] == v) return v;
	return com[v] = get(com[v]);
}

int mer(int x, int y){
	if(x == 0) return y;
	if(y == 0) return x;
	if(w[x-1] > w[y-1]) return x;
	return y;
}

int lev[200200];


void dfs(int v,int pa){
	p[0][v] = pa;
	for(int i = 1; i < 20; i++){
		p[i][v] = p[i-1][p[i-1][v]];
		up[i][v] = mer(up[i-1][v], up[i-1][p[i-1][v]]);
	}
	lev[v] = lev[pa] + 1;
	for(int i = 0; i < g[v].size(); i++){
		int id = g[v][i];
		int to = a[id] ^ b[id] ^ v;
		if(to == pa) continue;
		up[0][to] = id + 1;
		dfs(to, v);
	}
}
int getlca(int u, int v){
	if(lev[u] < lev[v]) swap(u, v);
	for(int i = 19; i >= 0; i--){
		if(lev[u] - (1<<i) >= lev[v]) u = p[i][u];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--){
		if(p[i][u] != p[i][v]){
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][v];
}
int get_mx(int a, int len){
	int cur = 0;
	for(int i = 19; i>= 0; i--){
		if(len & (1<<i)){
			cur = mer(cur, up[i][a]);
			a = p[i][a];
		}
	}
	return cur;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		com[i] = i;
	for(int i = 0; i < m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a[i], &b[i]);
		per[i] = i;
	}
	sort(per, per + m, cmp);
	for(int i = 0; i < m; i++){
		int x = a[per[i]];
		int y = b[per[i]];
		if(get(x) != get(y)){
			com[get(x)] = get(y);
			g[x].pb(per[i]);
			g[y].pb(per[i]);
			ok[per[i]] = 1;
		}
	}
	dfs(1, 0);
	int S;
	scanf("%d", &S);
	ll sum = 0;
	for(int i = 0; i < m; i++){
		if(ok[i]) sum += w[i];
	}
	ll ans = (1ll<<50);
	int ind = -1;
	for(int i = 0; i < m; i++){
		if(ok[i]){
			ll cur = sum - S/c[i];
			if(cur<ans){
				ans = cur;
				ind = i;
			}
		}else{
			int lca = getlca(a[i], b[i]);
			int mx = mer(get_mx(a[i], lev[a[i]] - lev[lca]), get_mx(b[i], lev[b[i]] - lev[lca]));
			ll cur = sum - w[mx-1] + w[i] - S/c[i];
			if(cur < ans){
				ans = cur;
				ind = i;	
			}
		}
	}
	printf("%I64d\n", ans);
	if(ok[ind]){
		for(int i = 0; i < m; i++){
			if(!ok[i]) continue;
			if(i == ind){
				printf("%d %d\n", i +1, w[i] - S/c[i]);
			}else printf("%d %d\n", i +1, w[i]);
		}
	}else{
		int lca = getlca(a[ind], b[ind]);
		int mx = mer(get_mx(a[ind], lev[a[ind]] - lev[lca]), get_mx(b[ind], lev[b[ind]] - lev[lca])) - 1;
		for(int i = 0; i < m; i++){
			if(i == mx) continue;
			if(ind == i){
				printf("%d %d\n", i+1, w[i] - S/c[i]);
				continue;
			}
			if(ok[i]){
				printf("%d %d\n", i+1, w[i]);
			}
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}