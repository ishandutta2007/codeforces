#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, k, to[105], edge[105][105];
bool dp[10][(1 << 6) + 11];
map<pair<ll, ll>, bool> M;
vector<vector<pii>> vec;
vector<vector<VI>> group;
ll ans, fac[105];
void dfs0(int lvl) {
	if(to[lvl]) return dfs0(lvl + 1);
	if(lvl == n + 1) {
		vector<pii> cur;
		rep(i, 1, n) if(i < to[i]) cur.pb(mp(i, to[i]));
		vec.pb(cur);
		return;
	}
	rep(i, lvl + 1, n) {
		if(to[i]) continue;
		to[lvl] = i;
		to[i] = lvl;
		dfs0(lvl + 1);
		to[lvl] = to[i] = 0;
	}
}
void dfs1(int lvl, int dep) {
	if(lvl == n / 2 + 1) {
		vector<VI> cur;
		cur.resize(dep);
		rep(i, 1, n / 2) cur[to[i] - 1].pb(i - 1);
		group.pb(cur);
		return;
	}
	rep(i, 1, dep + 1) {
		to[lvl] = i;
		dfs1(lvl + 1, max(dep, i));
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	fac[0] = 1;
	rep(i, 1, k) fac[i] = fac[i - 1] * i;
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u][v] = edge[v][u] = 1;
	}
	dfs0(1);
	dfs1(1, 0);
	// for(auto y : group) {
	// 	printf("{");
	// 	for(auto z : y) {
	// 		printf("{");
	// 		for(auto x : z) printf("%d ", x);
	// 		printf("}, ");
	// 	}
	// 	printf("}\n");
	// }
	for(auto x : vec) {
		memset(dp, 0, sizeof dp);
		rep(i, 0, n / 2 - 1) {
			if(edge[x[i].fi][x[i].se]) dp[i][(1 << i)] = 1;
		}
		rep(s, 1, (1 << (n / 2)) - 1) {
			rep(i, 0, n / 2 - 1) {
				if(!dp[i][s]) continue;
				rep(j, 0, n / 2 - 1) {
					if(s >> j & 1) continue;
					if((edge[x[i].fi][x[j].fi] && edge[x[i].se][x[j].se]) || (edge[x[i].fi][x[j].se] && edge[x[i].se][x[j].fi])) {
						dp[j][s | (1 << j)] = 1;
					}
				}
			}
		}
		bool flag = 0;
		rep(i, 0, n / 2 - 1) flag |= dp[i][(1 << (n / 2)) - 1];
		if(!flag) continue;
		// printf("Find Hamilton Path\n");
		// rep(i, 0, n / 2 - 1) printf("%d %d\n", x[i].fi, x[i].se);
		// printf("\n");
		for(auto y : group) {
			int cnt = 0;
			ll u = 0, v = 0;
			for(auto z : y) {
				cnt++;
				if(cnt <= 3) u <<= 12;
				else v <<= 12;
				for(auto w : z) {
					if(cnt <= 3) {
						u |= (1 << (x[w].fi - 1));
						u |= (1 << (x[w].se - 1));
					} else {
						v |= (1 << (x[w].fi - 1));
						v |= (1 << (x[w].se - 1));
					}
				}
			}
			if(M[mp(u, v)]) continue;
			M[mp(u, v)] = 1;
			if(cnt <= k) ans += fac[k] / fac[k - cnt];
			// printf("CCC%d\n", cnt);
		}
	}
	printf("%lld\n", ans);
	return 0;
}