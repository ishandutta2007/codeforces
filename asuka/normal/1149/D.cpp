#include<bits/stdc++.h>
#define ll long long
#define N 75
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
int n, m, A, B, fa[N], siz[N], S = -1, dis[1 << 17][N], bel[N], ans[N];
bool vis[1 << 17][N];
queue<pii> qa, qb;
vector<pii> e[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) return;
	fa[v] = u;
	siz[u] += siz[v];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d", &n, &m, &A, &B);
	rep(i, 1, n) siz[i] = 1, fa[i] = i;
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
		if(w == A) uni(u, v);
	}
	memset(dis, 0x3f, sizeof dis);
	memset(ans, 0x3f, sizeof ans);
	rep(i, 1, n) if(find(i) == i && siz[i] > 3) {
		S++;
		rep(j, 1, n) if(find(j) == i) bel[j] = 1 << S;
	}
	dis[bel[1]][1] = 0;
	qa.push(mp(bel[1], 1));
	while(SZ(qa) + SZ(qb) > 0) {
		pii u;
		if(SZ(qb) == 0 || (SZ(qa) > 0 && dis[qa.front().fi][qa.front().se] < dis[qb.front().fi][qb.front().se])) u = qa.front(), qa.pop();
		else u = qb.front(), qb.pop();
		int d = dis[u.fi][u.se];
		ans[u.se] = min(ans[u.se], d);
		if(vis[u.fi][u.se]) continue;
		vis[u.fi][u.se] = 1;
		for(auto V : e[u.se]) {
			int v = V.fi, w = V.se;
			if(w == A) {
				if(dis[u.fi][v] > d + w) {
					dis[u.fi][v] = d + w;
					qa.push(mp(u.fi, v));
				}
			} else {
				if(u.fi & bel[v] || find(u.se) == find(v)) continue;
				if(dis[u.fi | bel[v]][v] > d + w) {
					dis[u.fi | bel[v]][v] = d + w;
					qb.push(mp(u.fi | bel[v], v));
				}
			}
		}
	}
	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}