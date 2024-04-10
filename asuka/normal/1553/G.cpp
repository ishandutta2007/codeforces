#include<bits/stdc++.h>
#define ll long long
#define N 150015
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
const int M = 1e6 + 1;
int pri[M + 11], tot, low[M + 11], notp[M + 11], id[M + 11];
void init(){
	rep(i, 2, M) {
		if(!notp[i]) {
			low[i] = i;
			pri[++tot] = i;
		}
		for(int j = 1; j <= tot && i * pri[j] <= M; ++j) {
			notp[i * pri[j]] = 1;
			low[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}
VI fac(int x){
	VI res;
	while(x > 1) {
		int k = low[x];
		res.pb(k);
		while(x % k == 0) x /= k;
	}
	return res;
}
namespace UF{
	int fa[N + M], siz[N + M], tot;
	int newnode(){
		tot++;
		fa[tot] = tot;
		siz[tot] = 1;
		return tot;
	}
	int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void uni(int u, int v) {
		u = find(u); v = find(v);
		if(u == v) return;
		if(siz[u] < siz[v]) swap(u, v);
		siz[u] += siz[v];
		fa[v] = u; 
	}
}
using namespace UF;
int n, q, a[N];
set<int> S[N + M];
unordered_map<int, int> ok[N + M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) newnode();
	rep(i, 1, n) {
		VI u = fac(a[i]);
		for(auto x : u) {
			// printf("%d ", x);
			if(!id[x]) id[x] = newnode();
			uni(id[x], i);
		}
		// printf("\n");
	}
	rep(i, 1, n) {
		VI u = fac(a[i] + 1);
		int fi = find(i);
		for(auto x : u) {
			if(!id[x]) continue;
			int fx = find(id[x]);
			S[fi].insert(fx); 
			for(auto y : u) {
				if(!id[y]) continue;
				int fy = find(id[y]);
				// printf("%d %d\n", x, y);
				ok[fx][fy] = ok[fy][fx] = 1;
			}
		}
	}
	while(q--) {
		int s, t, ans = 2;
		scanf("%d%d", &s, &t);
		int fs = find(s), ft = find(t);
		if(fs == ft) ans = min(ans, 0);
		if(S[fs].find(ft) != S[fs].end()) ans = min(ans, 1);
		if(S[ft].find(fs) != S[ft].end()) ans = min(ans, 1);
		if(ok[fs].count(ft) > 0) ans = min(ans, 1);
		printf("%d\n", ans);
	}
	return 0;
}
/*
5 1
3 8 7 6 25
3 5
*/