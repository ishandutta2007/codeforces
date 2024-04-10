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
const int mod = 1e9 + 7;
using ull = unsigned ll;
int n, m, f[1111][22], sons, son[22], dp[2][1 << 12], pa[22], ans, siz[22];
VI S[1111], T[22];
void inc(int &x, int y) {x = (x + y >= mod) ? (x + y - mod) : (x + y);}
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int calc(VI vec) {
	rep(p, 0, 1) rep(i, 0, (1 << sons) - 1) dp[p][i] = 0;
	int cur = 0, nxt = 1;
	dp[cur][0] = 1;
	for(auto x : vec) {
		rep(i, 0, (1 << sons) - 1) dp[nxt][i] = 0;
		rep(mask, 0, (1 << sons) - 1) {
			inc(dp[nxt][mask], dp[cur][mask]);
			rep(i, 0, sons - 1) {
				if(mask >> i & 1) continue;
				int y = son[i];
				inc(dp[nxt][mask | (1 << i)], (ll) dp[cur][mask] * f[x][y] % mod);
			}
		}
		swap(cur, nxt);
	}
	return cur;
}
void Sdfs0(int u, int fa, int tu) {
	VI vec;
	for(auto v : S[u]) if(v != fa) {
		Sdfs0(v, u, tu);
		vec.pb(v);
	}
	int p = calc(vec);
	f[u][tu] = dp[p][(1 << sons) - 1];
}
VI stk;
void Tdfs0(int u, int fa) {
	pa[u] = fa;
	for(auto v : T[u]) if(v != fa) {
		Tdfs0(v, u);
	}
	stk.pb(u);
	sons = 0;
	for(auto v : T[u]) if(v != fa) son[sons++] = v;
	if(sons == 0) {
		rep(i, 1, n) f[i][u] = 1;
		return;
	}
	Sdfs0(1, 0, u);
}
void recalc(VI vec, int u) {
	for(auto tu : stk) {
		sons = 0;
		for(auto tv : T[tu]) if(tv != pa[tu]) son[sons++] = tv;
		if(sons == 0) {
			f[u][tu] = 1;
			continue; 
		}
		int p = calc(vec);
		f[u][tu] = dp[p][(1 << sons) - 1];
		// if(u == 2) {
		// 	printf("!!! %d %d\n", u, tu);
		// 	printf("%d\n", f[u][tu]);
		// 	printf("%d %d\n", f[1][son[0]], f[3][son[0]]);
		// }
	}
}
void Sdfs1(int u, int fa) {
	// get f[u]
	int ori[22], oori[22];
	rep(i, 1, m) ori[i] = f[u][i];
	VI vec;
	for(auto v : S[u]) vec.pb(v);
	recalc(vec, u);
	// printf("root %d\n", u);
	// rep(i, 1, m) printf("%d ", f[u][i]);
	// printf("\n");
	rep(i, 1, m) oori[i] = f[u][i];
	inc(ans, f[u][1]);
	vector<VI> pre[13], suf[13];
	rep(i, 1, m) pre[i].resize(SZ(S[u])), suf[i].resize(SZ(S[u]));
	for(auto tu : stk) {
		sons = 0;
		for(auto tv : T[tu]) if(tv != pa[tu]) son[sons++] = tv;
		rep(i, 0, SZ(S[u]) - 1) {
			pre[tu][i].resize(1 << sons);
			int x = S[u][i];
			rep(mask, 0, (1 << sons) - 1) {
				inc(pre[tu][i][mask], i > 0 ? pre[tu][i - 1][mask] : (mask == 0));
				rep(j, 0, sons - 1) {
					if(mask >> j & 1) continue;
					int y = son[j];
					inc(pre[tu][i][mask | (1 << j)], (ll) (i > 0 ? pre[tu][i - 1][mask] : (mask == 0)) * f[x][y] % mod);
				}
			}
			// if(tu == 4) {
			// 	printf("preI: %d\n", i);
			// 	rep(mask, 0, (1 << sons) - 1) printf("%d %d\n", mask, pre[tu][i][mask]);
			// }
		}
		per(i, 0, SZ(S[u]) - 1) {
			suf[tu][i].resize(1 << sons);
			int x = S[u][i];
			rep(mask, 0, (1 << sons) - 1) {
				inc(suf[tu][i][mask], (i + 1 < SZ(S[u])) ? suf[tu][i + 1][mask] : (mask == 0));
				rep(j, 0, sons - 1) {
					if(mask >> j & 1) continue;
					int y = son[j];
					inc(suf[tu][i][mask | (1 << j)], (ll) ((i + 1 < SZ(S[u])) ? suf[tu][i + 1][mask] : (mask == 0)) * f[x][y] % mod);
				}
			}
			// if(tu == 4) {
			// 	printf("sufI: %d\n", i);
			// 	rep(mask, 0, (1 << sons) - 1) printf("%d %d\n", mask, suf[tu][i][mask]);
			// }
		}
	}
	rep(i, 0, SZ(S[u]) - 1) {
		int v = S[u][i];
		if(v == fa) continue;
		rep(j, 1, m) {
			f[u][j] = 0;
			sons = SZ(T[j]) - (pa[j] > 0);
			// printf("j: %d, %d\n", j, sons);
			if(sons == 0) f[u][j] = 1;
			else {
				if(SZ(S[u]) == 1) f[u][j] = 0;
				else {
					rep(mask, 0, (1 << sons) - 1) {
						// printf("%d %d\n", (i > 0 ? pre[j][i - 1][mask] : (mask == 0)), ((i + 1 < SZ(S[u])) ? suf[j][i + 1][((1 << sons) - 1) ^ mask] : (mask == (1 << sons) - 1)));
						inc(f[u][j], (ll) (i > 0 ? pre[j][i - 1][mask] : (mask == 0)) * ((i + 1 < SZ(S[u])) ? suf[j][i + 1][((1 << sons) - 1) ^ mask] : (mask == (1 << sons) - 1)) % mod);
					}
				}
			}
		}
		// printf("recalc %d without %d\n", u, v);
		// rep(j, 1, m) printf("%d ", f[u][j]);
		// printf("\n");
		Sdfs1(v, u);
		rep(j, 1, m) f[u][j] = oori[j];
	}
	rep(i, 1, m) f[u][i] = ori[i];
}
int vrt = inf, val[22];
int pri[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39, 41}, fac[22];
ull hs[22];
void Tdfs1(int u, int fa) {
	siz[u] = 1;
	for(auto v : T[u]) if(v != fa) {
		Tdfs1(v, u);
		siz[u] += siz[v];
		val[u] = max(val[u], siz[v]);
	}
	val[u] = max(val[u], m - siz[u]);
	if(val[u] < vrt) vrt = val[u];
}
map<ull, int> M;
int gethash(int u, int fa) {
	int res = 1;
	hs[u] = siz[u] = 1;
	for(auto v : T[u]) if(v != fa) {
		res = (ll) res * gethash(v, u) % mod;
		siz[u] += siz[v];
		hs[u] += hs[v] * pri[siz[v]];
	}
	M.clear();
	for(auto v : T[u]) if(v != fa) M[hs[v] * pri[siz[v]]]++;
	for(auto x : M) res = (ll) res * fac[x.se] % mod;
	return res;
}
int calcauto() {
	int rt[2] = {-1, -1}, res = 1;
	Tdfs1(1, 0);
	rep(i, 1, m) {
		if(val[i] == vrt) {
			if(rt[0] == -1) rt[0] = i;
			else rt[1] = i;
		}
	}
	// printf("%d %d\n", rt[0], rt[1]);
	if(rt[1] == -1) {
		res = gethash(rt[0], 0);
	} else {
		res = (ll) res * gethash(rt[0], rt[1]) % mod;
		res = (ll) res * gethash(rt[1], rt[0]) % mod;
		if(hs[rt[0]] == hs[rt[1]] && siz[rt[0]] == siz[rt[1]]) res = res * 2 % mod;
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		S[u].pb(v);
		S[v].pb(u);
	}
	scanf("%d", &m);
	fac[0] = 1;
	rep(i, 1, m) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 2, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].pb(v);
		T[v].pb(u);
	}
	Tdfs0(1, 0);
	// rep(i, 1, n) {
	// 	rep(j, 1, m) printf("%d ", f[i][j]);
	// 	printf("\n");
	// }
	Sdfs1(1, 0);
	int val = calcauto();
	// printf("%d\n", val);
	ans = (ll) ans * qpow(val, mod - 2) % mod;
	printf("%d\n", ans);
	return 0;
}