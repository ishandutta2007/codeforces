#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
#define IT multiset<int>::iterator
using std::max; using std::min; using std::multiset;
typedef long long LL;
const int N = 200005, M = 1000005;
int n, m, Q, a[N], b[N];
struct BIT {
	LL c[M + 5];
	void add(int i, int x) {
		for (; i <= M; i += lowbit(i)) c[i] += x;
	}
	LL qry(int i) {
		if (i < 0) return 0;
		if (i > M) i = M;
		LL ans = 0;
		for (; i; i -= lowbit(i)) ans += c[i];
		return ans;
	}
	LL qry(int l, int r) { return qry(r) - qry(l - 1); }
} A1, A2, B1, B2;
multiset<int> Sa, Sb;
LL calc(int k) {
	int l = min(k, min(*Sa.begin(), *Sb.begin()));
	return (A2.qry(1, M) - 1LL * n * l) - (B2.qry(k, M) - B1.qry(k, M) * k);
}
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), a[i]++, A1.add(a[i], 1), A2.add(a[i], a[i]), Sa.insert(a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]), b[i]++, B1.add(b[i], 1), B2.add(b[i], b[i]), Sb.insert(b[i]);
	while (Q--) {
		int op; scanf("%d", &op);
		if (op == 3) {
			int x; scanf("%d", &x);
			int minv = min(*Sa.begin(), *Sb.begin());
			LL ans = max(calc(minv - x), calc(*Sb.rbegin() - x));
			IT it = Sb.end(); int R = *--it + x, L = R + x;
			if (m > 1) L = *--it + x;
			it = Sa.upper_bound(R);
			if (it != Sa.end()) ans = max(ans, calc(*it - x) - (*it - min(minv, *it - x)) + x);
			if (it != Sa.begin()) --it, ans = max(ans, calc(*it - x) - (*it - min(minv, *it - x)) + x);
			it = Sa.lower_bound(L);
			if (it != Sa.begin()) --it, ans = max(ans, calc(*it - x) - (*it - min(minv, *it - x)) + x);
			printf("%lld\n", ans);
		} else {
			int pos, x; scanf("%d%d", &pos, &x);
			if (op == 1) {
				A1.add(a[pos], -1), A2.add(a[pos], -a[pos]), Sa.erase(Sa.find(a[pos]));
				a[pos] = x + 1;
				A1.add(a[pos], 1), A2.add(a[pos], a[pos]), Sa.insert(a[pos]);
			} else {
				B1.add(b[pos], -1), B2.add(b[pos], -b[pos]), Sb.erase(Sb.find(b[pos]));
				b[pos] = x + 1;
				B1.add(b[pos], 1), B2.add(b[pos], b[pos]), Sb.insert(b[pos]);
			}
		}
	}
	return 0;
}