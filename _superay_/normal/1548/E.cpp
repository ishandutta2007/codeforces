#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOGN = 18;
int n, m, X, na[N], nb[N], stk[N], lg2[N], bit[2][N];
pair<int, int> a[N], b[N], st[LOGN][N];
inline void add(int *bit, int i) {
	while (i < N) {
		bit[i]++;
		i += i & -i;
	}
}
inline int sum(int *bit, int i) {
	int ret = 0;
	while (i > 0) {
		ret += bit[i];
		i -= i & -i;
	}
	return ret;
}
inline int sum(int *bit, int l, int r) {
	return sum(bit, max(r, 0)) - sum(bit, max(l, 0));
}
inline pair<int, int> query(int l, int r) {
	int i = lg2[r - l + 1];
	return max(st[i][l], st[i][r - (1 << i) + 1]);
}
inline void calc(int n, pair<int, int> *a, int *na) {
	lg2[0] = -1;
	for (int i = 1; i <= n; i++) lg2[i] = lg2[i - 1] + ((i & (i - 1)) ? 0 : 1);
	for (int i = 1; i <= n; i++) st[0][i] = a[i];
	for (int i = 1; i < LOGN; i++) for (int j = 1; j <= n - (1 << i) + 1; j++)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	int tp;
	for (int i = 1; i <= n; i++) na[i] = N;
	tp = 0;
	for (int i = 1; i <= n; i++) {
		while (tp && a[stk[tp]] > a[i]) tp--;
		if (tp) na[i] = min(na[i], query(stk[tp], i).first);
		stk[++tp] = i;
	}
	tp = 0;
	for (int i = n; i >= 1; i--) {
		while (tp && a[stk[tp]] > a[i]) tp--;
		if (tp) na[i] = min(na[i], query(i, stk[tp]).first);
		stk[++tp] = i;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &X);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
	for (int i = 1; i <= m; i++) scanf("%d", &b[i].first), b[i].second = i;
	calc(n, a, na);
	calc(m, b, nb);
	vector<tuple<int, int, int> > buck;
	for (int i = 1; i <= n; i++) buck.emplace_back(na[i] - a[i].first, a[i].first, 0);
	for (int i = 1; i <= m; i++) buck.emplace_back(nb[i] - b[i].first, b[i].first, 1);
	sort(buck.rbegin(), buck.rend());
	long long ans = 0;
	for (auto &P : buck) {
		ans += sum(bit[get<2>(P) ^ 1], X - get<0>(P) - get<1>(P), X - get<1>(P));
		add(bit[get<2>(P)], get<1>(P));
	}
	printf("%lld\n", ans);
	return 0;
}