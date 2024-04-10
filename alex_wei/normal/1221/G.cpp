#include <bits/stdc++.h>
using namespace std;
const int N = 40;
vector <int> e[N], g[N], c;
int n, m, G, comp, single, rev[N], vis_e[N];
long long ans, f[4];
void dfs(int id) {
	c.push_back(id);
	vis_e[id] = 1, rev[id] = G++;
	for(int it : e[id]) if(!vis_e[it]) dfs(it);
}
bool bipartite, vis[N], col[N];
void check(int id) {
	vis[id] = 1;
	for(int it : g[id])
		if(vis[it]) bipartite &= col[id] ^ col[it];
		else col[it] = col[id] ^ 1, check(it);
}
void solve() {
	bipartite = 1;
	memset(vis, 0, sizeof vis);
	check(1);

	long long out[N];
	memset(out, 0, sizeof out);
	for(int i = 0; i < G; i++) for(int it : g[i]) out[i] |= 1ll << it;

	int lft = G >> 1, rt = G - lft; // G >> 1 -> lft
	static int msk[1 << 20];
	memset(msk, 0, sizeof msk);
	for(int i = 0; i < lft; i++) for(int it : g[i]) if(it >= lft) msk[1 << i] |= 1 << it - lft;

	static int a[1 << 20];
	memset(a, 0, sizeof a);
	for(int i = 0; i < 1 << rt; i++) {
		bool legal = 0;
		for(int j = 0; j < rt; j++) legal |= (i >> j & 1) && (out[j + lft] >> lft & i);
		a[i] += !legal;
	}
	for(int k = 1; k < 1 << rt; k <<= 1)
		for(int i = 0; i < 1 << rt; i += k << 1)
			for(int j = 0; j < k; j++)
				a[i | j | k] += a[i | j];
	
	long long cnt = 0;
	for(int i = 0; i < 1 << lft; i++) {
		for(int j = 0; j < lft; j++) if(i >> j & 1) msk[i] = msk[1 << j] | msk[i ^ (1 << j)];
		bool legal = 0;
		for(int j = 0; j < lft; j++) legal |= (i >> j & 1) && (out[j] & i);
		if(legal) cnt += 1 << rt;
		else cnt += (1 << rt) - (a[msk[i] ^ ((1 << rt) - 1)]);
	}

	static long long h[4];
	memset(h, 0, sizeof h);
	h[3] = (cnt + bipartite) * 2 - (1ll << G);
	h[1] = h[2] = cnt - h[3], h[0] = (1ll << G) - h[1] - h[2] - h[3];

	static long long tmpf[4];
	memset(tmpf, 0, sizeof tmpf);
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) tmpf[i | j] += f[i] * h[j];
	memcpy(f, tmpf, sizeof f);
}
int main() {
	f[0] = 1;
	cin >> n >> m;
	if(!m) cout << 0 << endl, exit(0);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v, u--, v--;
		e[u].push_back(v), e[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		if(vis_e[i]) continue;
		memset(rev, 0, sizeof(rev));
		for(int j = 0; j < G; j++) g[j].clear();
		G = 0, c.clear(), dfs(i);
		if(G == 1) {single++; continue;}
		comp++;
		for(int j : c) for(int it : e[j]) g[rev[j]].push_back(rev[it]);
		solve();
	}
	ans = f[3] - (1 << comp) + 2;
	cout << (ans << single) << endl;
	return 0;
}

/*
start thinking at 12:13

.
,  0, 1, 2 , DP .

n <= 40,  meet-in-the-middle.
,  1.
 1,  0, 2 .
 X, Y,  X .  0, 2, 02 .
.

 1 .
.  2 ^ {}
 02 ,  (2 ^ cnt - 2) .
2 ^ cnt  1 , 2  0  1 .
cnt .

 02, .
 1 .
.

,  0  2.
 0 ,  2 .
? , 0  2 .
 0 ,  cnt.
 02  2cnt - 2 ^ {|G|}.

,  02  2cnt - (2 ^ {|G|} - 2),  0  2.
?

 0 .
 X .
 X  0,  Y  0 ,  XY  0  Y  0  Y .
,  XY  0  Y , .
.
 n 2 ^ {n / 2}.
- 12:48

 m = 0
- 13:27

, 
- 13:39

finish debugging at 
*/