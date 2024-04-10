# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
struct SegTree{
	struct Node{
		ll s, tag;
		int ls, rs;
		Node(){
			tag = -1;
		}
	} t[MAXN * 4];
	int rt, tsz;
	int newnode(){
		tsz++;
		t[tsz].tag = -1;
		t[tsz].ls = t[tsz].rs = 0;
		t[tsz].s = 0;
		return tsz;
	}
	void update(int nw, int lft, int rgt){
		t[nw].s = max(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void push_down(int nw){
		if (t[nw].tag == -1) return;
		if (!t[nw].ls) t[nw].ls = newnode();
		if (!t[nw].rs) t[nw].rs = newnode();
		t[t[nw].ls].s = t[t[nw].ls].tag = t[nw].tag;
		t[t[nw].rs].s = t[t[nw].rs].tag = t[nw].tag;
		t[nw].tag = -1;
	}
	void modify(int &nw, int lft, int rgt, int l, int r, ll nm){
		// printf("modify %d %d %d %d %lld\n", lft, rgt, l, r, nm);
		if (!nw) nw = newnode();
		if (lft == l && rgt == r){
			t[nw].s = nm;
			t[nw].tag = nm;
			return;
		}
		push_down(nw);
		int mid = (lft + rgt) >> 1;
		if (l <= mid) modify(t[nw].ls, lft, mid, l, min(r, mid), nm);
		if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, nm);
		update(nw, lft, rgt);
	}
	ll getsum(int nw, int lft, int rgt, int l, int r){
		// printf("getsum %d %d %d %d %d %lld\n", nw, lft, rgt, l, r, t[nw].s);
		if (!nw) return 0;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		push_down(nw);
		ll ans = 0;
		if (l <= mid) ans = max(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = max(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
int t, n, cnt;
int a[MAXN], b[MAXN];
int dfn[MAXN], sz[MAXN];
vector <int> ga[MAXN], gb[MAXN];
void dfs0(int nw){
	dfn[nw] = ++cnt;
	sz[nw] = 1;
	int siz = gb[nw].size();
	for (int i = 0; i < siz; i++){
		int nxtn = gb[nw][i];
		dfs0(nxtn);
		sz[nw] += sz[nxtn];
	}
}
int dfs1(int nw, int ans){
	int tmp = sgt.getsum(sgt.rt, 1, n, dfn[nw], dfn[nw]);
	if (tmp){
		sgt.modify(sgt.rt, 1, n, dfn[tmp], dfn[tmp] + sz[tmp] - 1, 0);
		ans--;
	}
	bool flag = sgt.getsum(sgt.rt, 1, n, dfn[nw], dfn[nw] + sz[nw] - 1) == 0;
	if (flag){
		sgt.modify(sgt.rt, 1, n, dfn[nw], dfn[nw] + sz[nw] - 1, nw);
		ans++;
	}
	// printf("dfs1 %d %d %d %d %d %d\n", nw, dfn[nw], sz[nw], ans, tmp, flag);
	int siz = ga[nw].size();
	int fnl = ans;
	for (int i = 0; i < siz; i++){
		int nxtn = ga[nw][i];
		fnl = max(fnl, dfs1(nxtn, ans));
	}
	if (flag) sgt.modify(sgt.rt, 1, n, dfn[nw], dfn[nw] + sz[nw] - 1, 0);
	if (tmp) sgt.modify(sgt.rt, 1, n, dfn[tmp], dfn[tmp] + sz[tmp] - 1, tmp);
	return fnl;
}
int main(){
	scanf("%d", &t);
	while (t--){
		cnt = 0;
		sgt.tsz = sgt.rt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			ga[i].clear();
			gb[i].clear();
		}
		for (int i = 2; i <= n; i++){
			scanf("%d", a + i);
			ga[a[i]].push_back(i);
		}
		for (int i = 2; i <= n; i++){
			scanf("%d", b + i);
			gb[b[i]].push_back(i);
		}
		dfs0(1);
		printf("%d\n", dfs1(1, 0));
	}
	return 0;
}