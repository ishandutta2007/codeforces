# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1000051;
struct SegTree{
	struct Node{
		ll s1, s2;
		int ls, rs;
	} t[MAXN * 4];
	int tsz, rt;
	void update(int nw){
		t[nw].s1 = t[t[nw].ls].s1 + t[t[nw].rs].s1;
		t[nw].s2 = max(t[t[nw].ls].s2, t[t[nw].rs].s2);
	}
	void build(int &nw, int lft, int rgt, ll arr[]){
		nw = ++tsz;
		if (lft == rgt){
			t[nw].s1 = t[nw].s2 = arr[lft];
			return;
		}
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid, arr);
		build(t[nw].rs, mid + 1, rgt, arr);
		update(nw);
	}
	void modify1(int nw, int lft, int rgt, int pos, ll nm){
		if (lft == rgt){
			t[nw].s2 = t[nw].s1 = nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify1(t[nw].ls, lft, mid, pos, nm);
		else modify1(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
	void modify2(int nw, int lft, int rgt, int l, int r, ll nm){
		if (t[nw].s2 < nm) return;
		if (lft == rgt){
			t[nw].s2 = t[nw].s1 = t[nw].s1 % nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (l <= mid) modify2(t[nw].ls, lft, mid, l, min(mid, r), nm);
		if (r >= mid + 1) modify2(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, nm);
		update(nw);
	}
	ll getsum(int nw, int lft, int rgt, int l, int r){
		if (lft == l && rgt == r) return t[nw].s1;
		int mid = (lft + rgt) >> 1;
		ll ans = 0;
		if (l <= mid) ans += getsum(t[nw].ls, lft, mid, l, min(mid, r));
		if (r >= mid + 1) ans += getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r);
		return ans;
	}
} sgt;
int n, m;
ll a[MAXN];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	sgt.build(sgt.rt, 1, n, a);
	for (int i = 1; i <= m; i++){
		int op, l, r;
		ll val;
		scanf("%d", &op);
		if (op == 1){
			scanf("%d%d", &l, &r);
			printf("%lld\n", sgt.getsum(sgt.rt, 1, n, l, r));
		} else if (op == 2){
			scanf("%d%d%lld", &l, &r, &val);
			sgt.modify2(sgt.rt, 1, n, l, r, val);
		} else {
			scanf("%d%lld", &l, &val);
			sgt.modify1(sgt.rt, 1, n, l, val);
		}
	}
	return 0;
}