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
int p[22][100100];
int lev[100100];
vector<int> g[100100];
int tin[100100], tout[100100];
int timer = 0;

int root = 1;
ll t[4 *100100];
ll U[4*100100];
int a[100100];
int b[100100];
void dfs(int v, int pa = 0){
	tin[v] = timer++;
	p[0][v] = pa;
	for(int i = 1; i < 20; i++){
		p[i][v] = p[i-1][p[i-1][v]];
	}
	lev[v] = lev[pa]+1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == pa) continue;
		dfs(to, v);
	}
	tout[v] = timer-1;
}
void push(int v, int l, int r){
	U[v*2] += U[v];
	U[v*2+1] += U[v];
	int mid = (l+r)>>1;
	t[v*2] += U[v]*(mid + 1 - l);
	t[v*2+1] += U[v]*(r - mid);
	U[v]=0;
}
ll get(int v, int l, int r, int tl, int tr){
	if(tl > r || tr < l) return 0;
	if(tl <= l && r <= tr) return t[v];
	push(v, l, r);
	int mid = (l + r)>>1;
	return get(v * 2, l, mid, tl, tr) + get(v * 2 + 1, mid+1, r, tl, tr);
}

void add(int v, int l, int r, int tl, int tr, ll x){
	if(tl > r || tr < l) return;
	if(tl <= l && r <= tr) {
		U[v] += x;
		t[v] += x * 1ll * (r-l+1);
		return;
	}
	push(v, l, r);
	int mid = (l + r)>>1;
	add(v * 2, l, mid, tl, tr, x);
	add(v * 2 + 1, mid+1, r, tl, tr, x);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

int getLca(int u, int v){
	if(lev[u] < lev[v]) swap(u, v);
	for(int i = 19; i >= 0; i--){
		if(lev[u] - (1<<i) >= lev[v]) u = p[i][u];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--){
		if(p[i][u] != p[i][v])	{
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][u];
}
int getLev(int v, int len){
	
	for(int i = 19; i >= 0; i--){
		if(len & (1<<i)){
			v = p[i][v];
		}
	}
	return v;
}
void build(int v, int l, int r){
	if(l == r){
		t[v] = b[l];
		return;
	}
	int mid = (l+r)>>1;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid+1, r);
	t[v] = t[v * 2] + t[v * 2 + 1];
}
void solve(){
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1, u, v;i < n; i++){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		b[tin[i]] = a[i];
	}
	build(1, 0, n-1);
	for(int i = 0, t, u, v, x; i < q; i++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d", &v);
			root = v;
		}
		else if(t==2){
			scanf("%d%d%d", &u, &v, &x);
			int L = getLca(u, v);
			if(lev[u] < lev[v]) swap(u, v);
			if(root == L){
				add(1, 0, n-1, 0, n-1, x);
			}
			else if(tin[L] <= tin[root] && tout[L] >= tout[root]){
				if(tin[root] <= tin[u] && tout[root] >= tout[u]){
					add(1, 0, n-1, 0, n-1, x);	
				}else if(tin[root] <= tin[v] && tout[root] >= tout[v]){
					add(1, 0, n-1, 0, n-1, x);	
				}else{
					add(1, 0, n-1, 0, n-1, x);	
					int Z= root;
					for(int i = 19; i >= 0; i--){
						if(p[i][Z] == 0) continue;
						int gg = p[i][Z];
						if(tin[gg] <= tin[v] && tout[v] <= tout[gg]){
						}else if(tin[gg] <= tin[u] && tout[u] <= tout[gg]){
						
						}else Z = gg;
					}
					add(1, 0, n-1, tin[Z], tout[Z], -x);

				}
			}
			else{
				add(1, 0, n-1, tin[L], tout[L], x);
			}
		}
		else {
			scanf("%d", &v);
			ll ans = 0;
			if(tin[v] <= tin[root] && tout[root] <= tout[v]){
				if(root == v){
					ans = get(1, 0, n-1, 0, n-1);
				}else{
					int Z = getLev(root, lev[root] - lev[v] - 1);
					ans = get(1, 0, n-1, 0, n-1);
					ans -= get(1, 0, n-1, tin[Z], tout[Z]);
				}	
			}
			else {
				ans = get(1, 0, n-1, tin[v], tout[v]);
			}
			printf("%I64d\n", ans);
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