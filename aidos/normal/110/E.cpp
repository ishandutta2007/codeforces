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
#include <bitset>

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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
vector<pii> g[100100];
int dp[100100];
int good(int x) {
	while(x > 0) {
		if(x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}
int sz[100100];
void dfs(int v, int p){
	sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		if(to == p) continue;
		dfs(to, v);
		sz[v] += sz[to];
		if(g[v][i].s) dp[v] += sz[to];
		else dp[v] += dp[to];
	}
}
ll ans = 0;
void dfs2(int v, int p, int dpu){
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		if(to == p) continue;
		if(g[v][i].s) {
			dfs2(to, v, n - sz[to]);
		}else dfs2(to, v, dpu + dp[v] - dp[to]);
	}
	ans += (dpu + dp[v] - 1ll) * (dpu + dp[v]);
}


void solve(){
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb(mp(v, good(w)));
		g[v].pb(mp(u, good(w)));
	}
	dfs(1, 0);
	dfs2(1, 0, 0);
	cout << ans << "\n";
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