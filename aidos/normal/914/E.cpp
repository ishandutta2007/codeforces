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
int del[200200];
int cnt[(1<<20) + 10];
ll ans[200200];
char c[200200];

vector<int> ord, li, L;
int sz[200200];
int mx[200200];
ll D[200200];
vector<int> g[200200];
int a[200200];
int col[200200];
void fidfs(int v, int pa){
	sz[v] = 1;
	mx[v] = 0;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(del[to]) continue;
		if(to == pa) continue;
		fidfs(to, v);
		mx[v] = max(mx[v], sz[to]);
		sz[v] += sz[to];
	}
	D[v] = 0;
	ord.pb(v);
}

void dfs(int v, int pa){
	col[v] = col[pa] ^ a[v]; 
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(del[to]) continue;
		if(to == pa) continue;
		dfs(to, v);
	}
	li.pb(v);
}
void calc(int v, int pa){
	
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(del[to]) continue;
		if(to == pa) continue;
		calc(to, v);
		D[v] += D[to];
	}
	
	if(pa==0){
		ans[v] += (D[v]+1)/2;
	}
	else ans[v] += D[v];
}
void cen(int v){
	ord.clear();
	fidfs(v, 0);
	int H = ord.size();
	int CC = inf;
	int V = -1;
	for(int i = 0; i < H; i++){
		int cc = max(H - sz[ord[i]], mx[ord[i]]);
		if(cc < CC){
			CC = cc;
			V = ord[i];
		}
	}
	L.clear();
	col[V] = 0;
	cnt[0] = 1;
	for(int i = 0; i < g[V].size(); i++){
		int to = g[V][i];
		if(del[to]) continue;
		li.clear();
		dfs(to, V);
		for(int j = 0; j < li.size(); j++){
			for(int k = 0; k < 20; k++){
				D[li[j]] += cnt[col[li[j]] ^ a[V] ^ (1<<k)];
			}
			D[li[j]] += cnt[col[li[j]] ^ a[V]];
		}
		for(int j = 0; j < li.size(); j++){
			L.pb(li[j]);
			++cnt[col[li[j]]];
		}
	}

	for(int k = 0; k < 20; k++){
		D[V] += cnt[(1<<k)^a[V]];
	}
	D[V] += cnt[a[V]];
	for(int i = 0; i < L.size(); i++)
		cnt[col[L[i]]] = 0;
	cnt[0] = 0;
	for(int i = (int)(g[V].size())-1; i>=0; i--){
		int to = g[V][i];
		if(del[to]) continue;
		li.clear();
		dfs(to, V);
		for(int j = 0; j < li.size(); j++){
			for(int k = 0; k < 20; k++){
				D[li[j]] += cnt[col[li[j]] ^ a[V] ^ (1<<k)];
			}
			D[li[j]] += cnt[col[li[j]] ^ a[V]];
		}
		for(int j = 0; j < li.size(); j++){
			++cnt[col[li[j]]];
		}
	}
	for(int i = 0; i < L.size(); i++)
		cnt[col[L[i]]] = 0;
	calc(V, 0);
	del[V]=1;
	for(int i = 0; i < g[V].size(); i++){
		int to = g[V][i];
		if(del[to]) continue;
		cen(to);
	}

}
void solve(){
	int n;
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	scanf("%s", c);
	for(int i = 1; i <= n; i++){
		a[i] = (1<<(c[i-1] - 'a'));
	}
	cen(1);
	for(int i = 1; i <= n; i++){
		printf("%I64d%c", ans[i], " \n"[i == n]);
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