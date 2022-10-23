# include <bits/stdc++.h>
using namespace std;
const int MAXN = 250051;
const int INF = 0x3f3f3f3f;
struct SegTree{
	struct Node{
		int s;
		int ls, rs;
		Node(){
			s = INF;
		}
	} t[MAXN * 8];
	int tsz;
	void update(int nw){
		t[nw].s = min(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void build(int &nw, int lft, int rgt){
		nw = ++tsz;
		t[nw].s = INF;
		if (lft == rgt) return;
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
	}
	void modify(int nw, int lft, int rgt, int pos, int nm){
		if (lft == rgt){
			t[nw].s = nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, nm);
		else modify(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
	int getsum(int nw, int lft, int rgt, int l, int r){
		if (!nw) return INF;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		int ans = INF;
		if (l <= mid) ans = min(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = min(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
int r1, r2;
int t, n;
int a[MAXN];
int sk1[MAXN], sk2[MAXN], tp1, tp2;
int f[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sk1[0] = sk2[0] = n + 1;
		tp1 = tp2 = 0;
		sgt.tsz = 0;
		sgt.build(r1, 1, n);
		sgt.build(r2, 1, n);
		for (int i = n; i >= 1; i--){
			while (tp1 > 0 && a[sk1[tp1]] < a[i]) sgt.modify(r1, 1, n, sk1[tp1--], INF);
			while (tp2 > 0 && a[sk2[tp2]] > a[i]) sgt.modify(r2, 1, n, sk2[tp2--], INF);
			if (i == n) f[i] = 0;
			else f[i] = min(sgt.getsum(r1, 1, n, i, sk2[tp2] - 1), sgt.getsum(r2, 1, n, i, sk1[tp1] - 1)) + 1;
			sk1[++tp1] = sk2[++tp2] = i;
			sgt.modify(r1, 1, n, i, f[i]);
			sgt.modify(r2, 1, n, i, f[i]);
		}
		cout << f[1] << '\n';
	}
	return 0;
}