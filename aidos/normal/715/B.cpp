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

pll e[100100];
int en;
vector< int > g[100100];
ll dp[100100], d[100100];
int pr[100100];
int used[100100];
ll mi[100100];
int n, m, L, s, t;
void solve(){

	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
	ll cons = (ll) 1e9+1;
	for(int i = 0, a, b, w; i < m; i++){
		scanf("%d%d%d", &a, &b, &w);
		if(w == 0){
			g[a].pb(en);
			g[b].pb(en);

			e[en++] = mp(a ^ b, cons);
		}
		else {
			g[a].pb(en);
			g[b].pb(en);

			e[en++] = mp(a ^ b, w);
		}
	}
	for(int i = 0; i < n; i++){
		dp[i] = 2ll * cons * n;
	}
	dp[t] = 0;

	for(int i = 0; i< n; i++){
		int v = -1;
		for(int j = 0; j < n; j++){
			if(used[j]) continue;
			if(v == -1 || dp[v] > dp[j]) v = j;
		}
		used[v] = 1;
		for(int j = 0; j < g[v].size(); j++){
			int ind = g[v][j];
			int to = e[ind].f ^ v;
			if(used[to]) continue;
			if(e[ind].s < cons){
				dp[to] = min(dp[v] + e[ind].s, dp[to]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		d[i] = 2ll * cons * n;
		used[i] = 0;
	}
	d[s] = 0;

	for(int i = 0; i< n; i++){
		int v = -1;
		for(int j = 0; j < n; j++){
			if(used[j]) continue;
			if(v == -1 || d[v] > d[j]) v = j;
		}
		used[v] = 1;
		for(int j = 0; j < g[v].size(); j++){
			int ind = g[v][j];
			int to = e[ind].f ^ v;
			if(used[to]) continue;
			if(e[ind].s < cons){
				d[to] = min(d[v] + e[ind].s, d[to]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		used[i] = 0;
	}
	for(int i = 0; i< n; i++){
		int v = -1;
		for(int j = 0; j < n; j++){
			if(used[j]) continue;
			if(v == -1 || d[v] > d[j]) v = j;
		}
		used[v] = 1;
		for(int j = 0; j < g[v].size(); j++){
			int ind = g[v][j];
			int to = e[ind].f ^ v;
			if(e[ind].s < cons){
				d[to] = min(d[v] + e[ind].s, d[to]);
			}
			else {
				if(mi[ind] == 0){
					mi[ind] = max(L - d[v] - dp[to], 1ll);
				}
				else {
					mi[ind] = max(L-d[v]-dp[to], mi[ind]);
				}
				d[to] = min(d[v] + mi[ind], d[to]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		d[i] = 2ll * cons * n;
		used[i] = 0;

	}
	for(int i = 0; i < en; i++){
		if(e[i].s == cons)
			e[i].s = mi[i];
	}
	d[s] = 0;
	for(int i = 0; i< n; i++){
		int v = -1;
		for(int j = 0; j < n; j++){
			if(used[j]) continue;
			if(v == -1 || d[v] > d[j]) v = j;
		}
		used[v] = 1;
		for(int j = 0; j < g[v].size(); j++){
			int ind = g[v][j];
			int to = e[ind].f ^ v;
			d[to] = min(d[v] + e[ind].s, d[to]);
		}
	}
	if(d[t]!=L){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			int ind = g[i][j];
			int to = e[ind].f ^ i;
			if(to > i){
				printf("%d %d %I64d\n", to, i, e[ind].s);
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