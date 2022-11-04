#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int lson[N * 30], rson[N * 30], root[N], tot;
void Ins(int &rt, int l, int r, int pos) {
	rt = ++tot;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) Ins(lson[rt], l, mid, pos);
	else Ins(rson[rt], mid + 1, r, pos);
}
int Merge(int x, int y, int l, int r) {
	if (!x || !y) return x | y;
	int ret = ++tot;
	int mid = (l + r) >> 1;
	lson[ret] = Merge(lson[x], lson[y], l, mid);
	rson[ret] = Merge(rson[x], rson[y], mid + 1, r);
	return ret;
}
int Query(int rt, int l, int r, int lf, int rg) {
	if (!rt) return 0;
	if (lf <= l && r <= rg) return 1;
	int mid = (l + r) >> 1;
	if (lf <= mid && Query(lson[rt], l, mid, lf, rg)) return 1;
	if (mid < rg && Query(rson[rt], mid + 1, r, lf, rg)) return 1;
	return 0;
}
int go[N][26], pre[N], len[N], ep[N], cnt, last;
inline void sam_init() {
	cnt = last = 1;
	memset(go[1], 0, sizeof(go[1]));
	pre[1] = len[1] = 0;
}
inline int new_state(int _len) {
	cnt++;
	len[cnt] = _len;
	return cnt;
}
inline void sam_extend(int x) {
	int p = last, np = new_state(len[last] + 1);
	memset(go[np], 0, sizeof(go[np]));
	pre[np] = 0;
	while (p && !go[p][x]) {
		go[p][x] = np;
		p = pre[p];
	}
	if (!p) pre[np] = 1;
	else {
		int q = go[p][x];
		if (len[q] == len[p] + 1) {
			pre[np] = q;
		} else {
			int nq = new_state(len[p] + 1);
			ep[nq] = ep[q];
			memcpy(go[nq], go[q], sizeof(go[q]));
			pre[nq] = pre[q];
			pre[q] = pre[np] = nq;
			while (p && go[p][x] == q) {
				go[p][x] = nq;
				p = pre[p];
			}
		}
	}
	last = np;
}
int n, dp[N], tp[N];
char S[N];
int A[N], C[N];
int main() {
	scanf("%d %s", &n, S + 1);
	sam_init();
	for (int i = 1; i <= n; i++) {
		sam_extend(S[i] - 'a');
		Ins(root[last], 1, n, i);
		ep[last] = i;
	}
	for (int i = 0; i <= cnt; i++) C[i] = 0;
	for (int i = 1; i <= cnt; i++) C[len[i]]++;
	for (int i = 1; i <= cnt; i++) C[i] += C[i - 1];
	for (int i = 1; i <= cnt; i++) A[C[len[i]]--] = i;
	for (int i = cnt; i > 1; i--) {
		int p = A[i];
		root[pre[p]] = Merge(root[pre[p]], root[p], 1, n);
	}
	int ans = 1;
	for (int i = 2; i <= cnt; i++) {
		int p = A[i];
		if (pre[p] == 1) {
			dp[p] = 1;
			tp[p] = p;
			continue;
		}
		int fr = tp[pre[p]];
		if (Query(root[fr], 1, n, ep[p] - len[p] + len[fr], ep[p] - 1)) {
			dp[p] = dp[fr] + 1;
			tp[p] = p;
		} else {
			dp[p] = dp[fr];
			tp[p] = fr;
		}
		ans = max(ans, dp[p]);
	}
	printf("%d\n", ans);
	return 0;
}