# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
const int MAXV = MAXN * 2;
struct DSU{
	int fa[MAXV];
	int sz[MAXV];
	bool flag[MAXV];
	void clear(){
		for (int i = 0; i < MAXV; i++){
			fa[i] = i;
			sz[i] = (i < MAXN);
		}
	}
	DSU(){
		clear();
	}
	int findroot(int nw){
		if (fa[nw] == nw) return nw;
		else return fa[nw] = findroot(fa[nw]);
	}
	void merge(int u, int v){
//		printf("merge %d %d %d %d\n", u, v, findroot(u), findroot(v));
		u = findroot(u);
		v = findroot(v);
		if (u == v) return;
		fa[u] = v;
		sz[v] += sz[u];
		flag[v] |= flag[u];
//		printf("merge ed %d %d %d %d\n", u, v, findroot(u), findroot(v));
	}
	int getans(int nw){
//		printf("getans %d %d\n", nw, findroot(nw));
		nw = findroot(nw);
		if (flag[nw]) return sz[nw];
		else if (flag[MAXV - nw]) return sz[MAXV - nw];
		else return min(sz[nw], sz[MAXV - nw]);
	}
} dsu;
int n, k;
char s[MAXN];
int l[MAXN], r[MAXN];
int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	for (int i = 1; i <= k; i++){
		int c, u;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++){
			scanf("%d", &u);
			if (!l[u]) l[u] = s[u] == '1' ? MAXV - i : i;
			else r[u] = MAXV - i;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
//		printf("lr %d %d %d %d %d %d %d\n", i, l[i], r[i], dsu.findroot(l[i]), dsu.findroot(r[i]), dsu.getans(l[i]), dsu.getans(r[i]));
		if (l[i]){
			if (r[i]){
				int rl = dsu.findroot(l[i]), rr = dsu.findroot(r[i]);
				if (rl != rr){
					ans -= dsu.getans(rl);
					ans -= dsu.getans(rr);
					dsu.merge(rl, rr);
					dsu.merge(MAXV - rl, MAXV - rr);
					ans += dsu.getans(rr);
				}
			} else {
				int rl = dsu.findroot(l[i]);
				ans -= dsu.getans(rl);
				dsu.flag[rl] = true;
				ans += dsu.getans(rl);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}