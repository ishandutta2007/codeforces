#include<bits/stdc++.h>
using namespace std;
struct node {
	long long sum;
	int maxn, minn, tag;
}nd[800001];
int a[200001];
void update(int p) {
	nd[p].sum = nd[p*2].sum + nd[p*2+1].sum;
	nd[p].maxn = nd[p*2].maxn;
	nd[p].minn = nd[p*2+1].minn;
}
void pushdown(int p, int l, int r) {
	if (!nd[p].tag) return;
	int mid = (l + r) / 2;
	nd[p*2].sum = 1ll*(mid-l+1)*nd[p].tag;
	nd[p*2+1].sum = 1ll*(r-mid)*nd[p].tag;
	nd[p*2].maxn = nd[p*2].minn = nd[p*2+1].maxn = nd[p*2+1].minn = nd[p].tag;
	nd[p*2].tag = nd[p*2+1].tag = nd[p].tag;
	nd[p].tag = 0;
}
void build(int p, int l, int r) {
	if (l == r) {
		nd[p].sum = nd[p].maxn = nd[p].minn = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid), build(p * 2 + 1, mid + 1, r);
	update(p);
}
void modify(int p, int l, int r, int l0, int r0, int num) {
	if (l >= l0 && r <= r0) {
		nd[p].tag = num;
		nd[p].sum = 1ll*(r-l+1)*num;
		nd[p].maxn = nd[p].minn = num;
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if (l0 <= mid) modify(p * 2, l, mid, l0, r0, num);
	if (r0 > mid) modify(p * 2 + 1, mid + 1, r, l0, r0, num);
	update(p);
}
int query_lb(int p, int l, int r, int x) {
	if (nd[p].minn > x) return 0x3f3f3f3f;
	if (l == r) return l;
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	int ans = query_lb(p * 2, l, mid, x);
	if (ans == 0x3f3f3f3f) return query_lb(p * 2 + 1, mid + 1, r, x);
	return ans;
}
long long query_sum(int p, int l, int r, int l0, int r0) {
	if (l0 > r0) return 0;
	if (l >= l0 && r <= r0) return nd[p].sum;
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	long long ans = 0;
	if (l0 <= mid) ans += query_sum(p * 2, l, mid, l0, r0);
	if (r0 > mid) ans += query_sum(p * 2 + 1, mid + 1, r, l0, r0);
	return ans;
}
int query_rsum(int p, int l, int r, long long x) {
	if (nd[p].maxn > x) return 0;
	if (l == r) return l;
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	if (nd[p*2].sum + nd[p*2+1].maxn > x) return query_rsum(p * 2, l, mid, x);
	return query_rsum(p * 2 + 1, mid + 1, r, x - nd[p*2].sum);
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			int t = query_lb(1, 1, n, y);
			if (t <= x) modify(1, 1, n, t, x, y);
		}
		if (t == 2) {
			int ans = 0;
			while (x <= n) {
				int nx = query_rsum(1, 1, n, y+query_sum(1, 1, n, 1, x-1));
				ans += nx-x+1, y -= query_sum(1, 1, n, x, nx);
				if (nx == n) break;
				x = query_lb(1, 1, n, y);
			}
			cout << ans << endl;
		}
	}
}