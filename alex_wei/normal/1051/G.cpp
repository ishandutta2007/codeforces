#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = N << 5;
int n, node, fa[N], R[N], ls[K], rs[K];
long long ans, ma[N], sb[N], sab[N];
struct dat {
	int num;
	long long sum, val;
	dat operator + (dat x) {
		dat y;
		y.num = num + x.num;
		y.sum = sum + x.sum;
		y.val = val + x.val + sum * x.num;
		return y;
	}
} val[K];
void modify(int l, int r, int p, int &x) {
	if(!x) x = ++node;
	if(l == r) return val[x].num++, val[x].sum += p, void();
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
	val[x] = val[ls[x]] + val[rs[x]];
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	ls[x] = merge(ls[x], ls[y]), rs[x] = merge(rs[x], rs[y]);
	return val[x] = val[ls[x]] + val[rs[x]], x;
}
long long calc(int x) {
	long long toleft = sab[x] - ma[x] * sb[x];
	return val[R[x]].val - toleft;
}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge_ufs(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	ans -= calc(x), ans -= calc(y);
	ma[x] = min(ma[x], ma[y]), sb[x] += sb[y], sab[x] += sab[y];
	R[x] = merge(R[x], R[y]), fa[y] = x;
	ans += calc(x);
}
int main() {
	cin >> n;
	for(int i = 1; i < N; i++) fa[i] = i, ma[i] = i;
	for(int i = 1; i <= n; i++) {
		int a, b, p;
		scanf("%d %d", &a, &b), p = find(a), ans -= calc(p);
		sb[p] += b, sab[p] += 1ll * a * b, modify(1, n, b, R[p]), ans += calc(p);
		if(a > 1 && R[find(a - 1)]) merge_ufs(p, a - 1);
		int pos = ma[p] + val[R[p]].num;
		if(pos - 1 < N) merge_ufs(p, pos - 1);
		if(pos < N && R[find(pos)]) merge_ufs(p, pos);
		cout << ans << "\n";
	}
    return 0;
} ///////*/