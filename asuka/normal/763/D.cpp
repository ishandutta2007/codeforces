#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int pri[1000016], notp[1000015], tot;
void getPri() {
	rep(i, 2, 1000000) {
		if(!notp[i]) {pri[++tot] = i;}
		for(int j = 1; j <= tot && i * pri[j] <= 1000000; ++j) {
			notp[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}
using ull = unsigned ll;
int n, siz[N], diff;
int Mod[] = {1000000007, 1000000009, 192600817};
int f[N][3];
VI e[N];
map<tuple<int, int, int, int>, int> cnt;
void add(int x[], int sz) {
	auto u = make_tuple(x[0], x[1], x[2], sz);
	if(cnt[u]++ == 0) diff++;
}
void del(int x[], int sz) {
	auto u = make_tuple(x[0], x[1], x[2], sz);
	if(--cnt[u] == 0) diff--;
}
void dfs0(int u, int pa) {
	siz[u] = 1;
	rep(p, 0, 2) f[u][p] = 1;
	for(auto v : e[u]) if(v != pa) {
		dfs0(v, u);
		siz[u] += siz[v];
		rep(p, 0, 2) (f[u][p] += (ll) f[v][p] * pri[siz[v]] % Mod[p]) %= Mod[p];
	}
	add(f[u], siz[u]);
}
int ans, pos = 1, res[N];
void dfs1(int u, int pa) {
	if(diff > ans) ans = diff, pos = u;
	// printf("!%d %d\n", u, diff);
	res[u] = diff;
	for(auto v : e[u]) {
		if(v == pa) continue;
		int ou = siz[u], ov = siz[v], ofu[3], ofv[3];
		rep(p, 0, 2) ofu[p] = f[u][p], ofv[p] = f[v][p];
		siz[u] -= siz[v];
		siz[v] += siz[u];
		del(f[u], ou);
		del(f[v], ov);
		rep(p, 0, 2) (f[u][p] += Mod[p] - (ll) f[v][p] * pri[ov] % Mod[p]) %= Mod[p];
		rep(p, 0, 2) (f[v][p] += (ll) f[u][p] * pri[siz[u]] % Mod[p]) %= Mod[p];
		add(f[u], siz[u]);
		add(f[v], siz[v]);
		dfs1(v, u);
		del(f[u], siz[u]);
		del(f[v], siz[v]);
		siz[u] = ou;
		siz[v] = ov;
		rep(p, 0, 2) f[u][p] = ofu[p];
		rep(p, 0, 2) f[v][p] = ofv[p];
		add(f[u], siz[u]);
		add(f[v], siz[v]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	getPri();
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs0(1, 0);
	dfs1(1, 0);
	printf("%d\n", pos);
	// rep(i, 1, n) printf("%d ", res[i]);
	return 0;
}