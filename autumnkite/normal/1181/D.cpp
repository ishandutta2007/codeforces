#include <cstdio>
#include <cctype>
#include <algorithm>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 500005
long long n;
int m, q, ans[N];
std :: pair<int, int> a[N];
std :: pair<long long, int> Q[N];
struct Segment_Tree{
	int sum[N << 2];
	void insert(int u, int l, int r, int x){
		++sum[u];
		if (l == r) return;
		int md = (l + r) >> 1;
		if (x <= md) insert(u << 1, l, md, x);
		else insert(u << 1 | 1, md + 1, r, x);
	}
	int kth(int u, int l, int r, int k){
		if (l == r) return l;
		int md = (l + r) >> 1;
		if (k <= sum[u << 1]) return kth(u << 1, l, md, k);
		else return kth(u << 1 | 1, md + 1, r, k - sum[u << 1]);
	}
}T;
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 1; i <= m; ++i) a[i].second = i;
	for (register int i = 1; i <= n; ++i) ++a[read()].first;
	std :: sort(a + 1, a + 1 + m);
	for (register int i = 1; i <= q; ++i) Q[i].first = read(), Q[i].second = i;
	std :: sort(Q + 1, Q + 1 + q);
	int xa = 0, xq = 1, s = 0;
	while (xq <= q){
		++xa, s = a[xa].first, T.insert(1, 1, m, a[xa].second);
		while (xa < m && a[xa + 1].first == a[xa].first) ++xa, T.insert(1, 1, m, a[xa].second);
		if (xa == m){
			for (; xq <= q; ++xq) ans[Q[xq].second] = (Q[xq].first - n - 1) % m + 1;
			break;
		}
		for (; xq <= q && Q[xq].first <= n + 1ll * xa * (a[xa + 1].first - s); ++xq)
			ans[Q[xq].second] = T.kth(1, 1, m, (Q[xq].first - n - 1) % xa + 1);
		n += 1ll * xa * (a[xa + 1].first - s);
	}
	for (register int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
}