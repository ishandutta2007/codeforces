# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 100051;
int n;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int a[MAXN], asz;
int fa[MAXN];
void dfs0(int nw){
	a[++asz] = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		fa[nxtn] = nw;
		dfs0(nxtn);
	}
}
int f[MAXN], f1[MAXN];
int st[MAXN], tp;
int ans[MAXN];
int work(int k){
	if (ans[k] != -1) return ans[k];
	if (k == 1) return ans[k] = n;
	for (int i = asz; i >= 1; i--){
		int nw = a[i];
		int mx = 1;
		bool flag = false;
		f[nw] = 0;
		f1[nw] = 0;
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (nxtn == fa[nw]) continue;
			f[nw] += f[nxtn];
			if (f1[nxtn] + mx >= k) flag = true;
			mx = max(mx, f1[nxtn] + 1);
		}
		if (flag) f[nw]++;
		else f1[nw] = mx;
	}
	return ans[k] = f[1];
}
int main(){
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs0(1);
	int B = 1000;
	for (int i = 1; i <= B; i++){
		ans[i] = work(i);
	}
	int lt = B;
	for (int i = ans[B]; i >= 1; i--){
		int lft = lt + 1, rgt = n / i, res = lt;
		while (ans[st[tp]] >= i) lft = max(lft, st[tp--]);
		if (tp) rgt = min(rgt, st[tp] - 1);
		while (lft <= rgt){
			int mid = (lft + rgt) >> 1;
			if (work(mid) >= i){
				res = mid;
				lft = mid + 1;
			} else {
				rgt = mid - 1;
				st[++tp] = mid;
			}
		}
		while (lt < res) ans[++lt] = i;
	}
	while (lt < n) ans[++lt] = 0;
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}