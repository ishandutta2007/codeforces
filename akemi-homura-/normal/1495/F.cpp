#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOGN = 18;
int n, q, p[N], stk[N], L[LOGN][N], R[LOGN][N];
long long a[N], b[N], LC[LOGN][N], RC[LOGN][N];
inline long long getdist(int u, int v) {
	long long ret = 0;
	for (int i = LOGN - 1; i >= 0; i--) if (R[i][u] <= v) {
		ret += RC[i][u];
		u = R[i][u];
	}
	if (u == v) return ret;
	for (int i = LOGN - 1; i >= 0; i--) if (L[i][v] >= u) {
		ret += LC[i][v];
		v = L[i][v];
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	p[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	int tp = 0;
	stk[++tp] = n + 1;
	for (int j = 0; j < LOGN; j++) {
		R[j][n + 1] = n + 1;
		RC[j][n + 1] = 0;
	}
	for (int i = n; i >= 1; i--) {
		while (tp && p[stk[tp]] < p[i]) tp--;
		R[0][i] = stk[tp];
		RC[0][i] = b[i] = min(b[i], a[i] + getdist(i + 1, stk[tp]));
		for (int j = 1; j < LOGN; j++) {
			R[j][i] = R[j - 1][R[j - 1][i]];
			RC[j][i] = RC[j - 1][i] + RC[j - 1][R[j - 1][i]];
		}
		stk[++tp] = i;
	}
	tp = 0;
	stk[++tp] = 1;
	for (int j = 0; j < LOGN; j++) {
		L[j][1] = L[j][0] = 0;
		LC[j][1] = 0;
	}
	for (int i = 2; i <= n + 1; i++) {
		while (tp && p[stk[tp]] < p[i]) tp--;
		L[0][i] = tp ? stk[tp] : 0;
		LC[0][i] = tp ? a[stk[tp]] + getdist(stk[tp] + 1, i) : 0;
		for (int j = 1; j < LOGN; j++) {
			L[j][i] = L[j - 1][L[j - 1][i]];
			LC[j][i] = LC[j - 1][i] + LC[j - 1][L[j - 1][i]];
		}
		stk[++tp] = i;
	}
	set<int> st;
	st.insert(1);
	st.insert(n + 1);
	long long sum = getdist(1, n + 1);
	while (q--) {
		int x;
		scanf("%d", &x);
		if (x != 1) {
			if (st.count(x)) {
				auto it = st.find(x);
				int prv = *prev(it), nxt = *next(it);
				sum += getdist(prv, nxt);
				sum -= getdist(prv, x);
				sum -= getdist(x, nxt);
				st.erase(it);
			} else {
				auto it = st.insert(x).first;
				int prv = *prev(it), nxt = *next(it);
				sum -= getdist(prv, nxt);
				sum += getdist(prv, x);
				sum += getdist(x, nxt);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}