#include<bits/stdc++.h>
#define ll long long
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
const int N = 200015;
int T, n, m, Xor[N], fa[N], tag[N], siz[N];
vector<pii> e[N];
int find(int x) {return x == fa[x] ? x : find(fa[x]);}
int col(int x) {
	int res = 0;
	while(x ^ fa[x]) res ^= tag[x], x = fa[x];
	return res;
}
void uni(int u, int v, int w) {
	w = col(u) ^ col(v) ^ w;
	u = find(u); v = find(v);
	if(siz[u] > siz[v]) swap(u, v);
	fa[u] = v;
	tag[u] = w;
	siz[v] += siz[u];
}

void dfs0(int u, int pa) {
	for(auto [v, w] : e[u]) {
		if(v == pa) continue;
		Xor[v] = Xor[u] ^ max(0, w);
		dfs0(v, u);
		if(~w) uni(u, v, 0);
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) e[i].clear(), fa[i] = i, tag[i] = 0, siz[i] = 1;
		vector<pii> edge;
		vector<array<int, 3>> edge2;
		rep(i, 2, n) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(w == -1) edge.pb(mp(u, v));
			else edge2.pb({u, v, w});
			e[u].pb(mp(v, w));
			e[v].pb(mp(u, w));
		}
		dfs0(1, 0);
		bool ans = 1;
		rep(i, 1, m) {
			int u, v, p;
			scanf("%d%d%d", &u, &v, &p);
			int o = Xor[u] ^ Xor[v], oo = __builtin_popcount(o) & 1;
			if(find(u) == find(v)) {
				ans &= (col(u) ^ col(v)) == (oo ^ p);
			} else {
				uni(u, v, oo ^ p);
			}
		}
		if(!ans) {
			puts("NO");
			continue;
		}
		puts("YES");
		for(auto [u, v] : edge) {
			if(find(u) == find(v)) {
				printf("%d %d %d\n", u, v, col(u) ^ col(v));
			} else {
				printf("%d %d %d\n", u, v, 0);
				uni(u, v, 0);
			}
		}
		for(auto o : edge2) printf("%d %d %d\n", o[0], o[1], o[2]);
	}
	return 0;
}