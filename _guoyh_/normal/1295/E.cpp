# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct SegTree{
	struct Node{
		ll s, tag;
		Node *ls, *rs;
	} pool[MAXN * 4];
	int sz, tsz;
	Node *rt;
	Node* newnode(){
		tsz++;
		(pool + tsz) -> s = 0;
		return pool + tsz;
	}
	void update(Node *nw){
		nw -> s = 1e18;
		if (nw -> ls) nw -> s = min(nw -> s, nw -> ls -> s);
		if (nw -> rs) nw -> s = min(nw -> s, nw -> rs -> s);
	}
	void pushDown(Node *nw){
		if (!nw -> ls) nw -> ls = newnode();
		if (!nw -> rs) nw -> rs = newnode();
		nw -> ls -> s += nw -> tag;
		nw -> rs -> s += nw -> tag;
		nw -> ls -> tag += nw -> tag;
		nw -> rs -> tag += nw -> tag;
		nw -> tag = 0;
	}
	void modify(Node *&nw, int lft, int rgt, int l, int r, ll nm){
		// printf("modify %d %d %d %d %lld\n", lft, rgt, l, r, nm);
		if (!nw) nw = newnode();
		if (lft == l && rgt == r){
			nw -> s += nm;
			nw -> tag += nm;
			return;
		}
		pushDown(nw);
		int mid = (lft + rgt) >> 1;
		if (l <= mid) modify(nw -> ls, lft, mid, l, min(mid, r), nm);
		if (r >= mid + 1) modify(nw -> rs, mid + 1, rgt, max(l, mid + 1), r, nm);
		update(nw);
	}
	void modify(int l, int r, ll nm){
		modify(rt, 0, sz, l, r, nm);
	}
	ll getD(){
		return rt -> s;
	}
} sgt;
int n;
int a[MAXN], p[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sgt.sz = n;
	ll ans = 1e18;
	for (int i = 1; i <= n; i++) sgt.modify(p[i], n, a[i]);
	for (int i = 1; i <= n - 1; i++){
		// printf("%d\n", i);
		sgt.modify(p[i], n, -a[i]);
		sgt.modify(0, p[i] - 1, a[i]);
		ans = min(ans, sgt.getD());
	}
	printf("%lld\n", ans);
	return 0;
}