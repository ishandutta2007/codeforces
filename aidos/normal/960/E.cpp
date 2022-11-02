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
int mod = 1000 * 1000 * 1000 + 7;
int n;
int V[200200];
vector<int> g[200200];
int sz[200200];
int cnt[200200][2];

int C[200200][2];
int lev[200200];

ll ans;
void dfs(int v, int p){
	lev[v] = lev[p]^1;
	sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		sz[v] += sz[to];
		cnt[v][0] += cnt[to][0];
		cnt[v][1] += cnt[to][1];
	}
	cnt[v][lev[v]]++;
}
void dfs2(int v, int p){
	ans = (ans + V[v] * 1ll * (cnt[1][lev[v]] - cnt[v][lev[v]] + 1) % mod * sz[v] % mod) % mod;
	ans = (ans +mod- V[v] * 1ll * (cnt[1][1^lev[v]] - cnt[v][1^lev[v]]) % mod * sz[v] % mod) % mod;
	ans = (ans + V[v] * 1ll * (n - sz[v])) % mod;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs2(to, v);
		ans = (ans + V[v] * 1ll * (n-sz[to])  % mod * 1ll * (cnt[to][lev[v]]) % mod) % mod;
		ans = (ans + mod - V[v] * 1ll * (n-sz[to])  % mod * 1ll * (cnt[to][1^lev[v]]) % mod) % mod;	 
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &V[i]);
		V[i] =( V[i] + mod) % mod;
	}
	for(int i = 2, x, y; i <= n; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	dfs2(1, 0);
	cout << ans << endl;
	
}	

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}