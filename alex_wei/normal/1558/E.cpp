#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N], b[N];
int extend[N], vis[N], fr[N], found;
vector <int> e[N];
void ext(int u) {found = 1; while(!extend[u]) extend[u] = 1, u = fr[u];}
void dfs(int id, int fa, long long val) {
	if(vis[id]) return ext(id), ext(fa), void();
	vis[id] = 1, fr[id] = fa;
	for(int it : e[id]) if(it != fa && val > a[it]) dfs(it, id, val + b[it]);
}
bool check(int val) {
	memset(extend, 0, sizeof(extend)), extend[1] = 1;
	while(1) {
		memcpy(vis, extend, sizeof(vis));
		bool not_extend = found = 0;
		long long tot = val;
		for(int i = 1; i <= n; i++) extend[i] ? tot += b[i] : not_extend = 1;
		if(!not_extend) return 1;
		for(int i = 1; i <= n && !found; i++) {
			if(!extend[i]) continue;
			for(int it : e[i]) {
				if(extend[it]) continue;
				if(tot > a[it]) dfs(it, i, tot + b[it]);
			}
		}
		if(!found) return 0;
	}
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 2; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) cin >> b[i];
	for(int i = 1, u, v; i <= m; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	int l = 1, r = 1e9 + 1;
	while(l < r) {
		int m = l + r >> 1;
		check(m) ? r = m : l = m + 1;
	}
	cout << l << endl;
}
int main() {
	// freopen("1.in", "r", stdin);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
2022/5/1
start thinking at 15:44

.

.
O(nm) ???
???
?
.

, .
.

,  dfs.
 x in S dfs  y  z,  y  extend  z , z  extend .
.

start coding at 20:35
finish debugging at 21:00
*/