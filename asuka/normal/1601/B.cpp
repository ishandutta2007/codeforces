#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n, a[N], b[N], from[N][2], dis[N][2];
VI vec[N];
queue<pii> q;
int Min[N << 2], id[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) {
	if(Min[ls] < Min[rs]) id[p] = id[ls];
	else id[p] = id[rs];
	Min[p] = min(Min[ls], Min[rs]);
}
pii query(int p, int l, int r, int x, int y) {
	if(x <= l && r <= y) return mp(Min[p], id[p]);
	int mid = (l + r) >> 1;
	pii res = mp(inf, inf);
	if(x <= mid) res = min(res, query(ls, l, mid, x, y));
	if(y > mid) res = min(res, query(rs, mid + 1, r, x, y));
	return res;
}
void upd(int p, int l, int r, int pos) {
	if(l == r) {
		Min[p] = id[p] = inf;
		return;
	}
	int mid = (l + r) >>1;
	if(pos <= mid) upd(ls, l, mid, pos);
	else upd(rs, mid + 1, r, pos);
	pushup(p);
}
void build(int p, int l, int r) {
	if(l == r) {
		Min[p] = l - a[l];
		id[p] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]); // i -> [i - a[i], i]
	rep(i, 1, n) scanf("%d", &b[i]), vec[i + b[i]].pb(i); // i -> i + b[i]
	build(1, 1, n);
	memset(dis, 0x3f, sizeof dis);
	q.push(mp(0, 0));
	dis[0][0] = 1;
	while(!q.empty()) {
		pii U = q.front();
		q.pop();
		int u = U.fi, uu = U.se;
		// printf("U %d %d\n", u, uu);
		if(uu == 1) {
			for(auto x : vec[u]) {
				if(dis[x][0] > dis[u][1] + 1) {
					dis[x][0] = dis[u][1] + 1;
					from[x][0] = u;
					q.push(mp(x, 0));
				}
			}
		} else {
			while(1) {
				pii V = query(1, 1, n, u + 1, n);
				// printf("%d %d\n", V.fi, V.se);
				if(V.fi > u) break;
				int v = V.se;
				if(dis[v][1] > dis[u][0] + 1) {
					dis[v][1] = dis[u][0] + 1;
					from[v][1] = u;
					q.push(mp(v, 1));
					upd(1, 1, n, v);
				}
			}
		}
	}
	if(dis[n][1] == inf) return puts("-1"), 0;
	printf("%d\n", (dis[n][1] + 1) / 2);
	int cur = n, flag = 1;
	while(1) {
		cur = from[cur][flag];
		flag ^= 1;
		printf("%d ", cur);
		if(!cur) break;
		cur = from[cur][flag];
		flag ^= 1;
	}
	return 0;
}