#include <bits/stdc++.h>
typedef long long LL;
typedef std::vector<int> String;
const int N = 100005, P = 1e9 + 7, inv2 = (P+1)>>1;
int n, m, q, idx, T;
char s[105], t[N], w[N*10];
int suf[N][26], bas2[N], ibas2[N];
int dfs(String U, int z, int top) { // = y (mod x)
	if (z == top) return 0;
	if (U.size() == 1) return 1LL * bas2[top] * (P + suf[top][U[0]] - suf[z][U[0]]) % P;
	String U0, U1;
	for (int i = 0; i < U.size(); i++)
		if (i & 1) U0.push_back(U[i]);
		else U1.push_back(U[i]);
	int ok, ans = 0;
	ok = 1;
	for (int i = 0; i < U0.size(); i++)
		if (U0[i] != t[z] - 'a') { ok = 0; break; }
	if (ok) ans += dfs(U1, z+1, top);
	ok = 1;
	for (int i = 0; i < U1.size(); i++)
		if (U1[i] != t[z] - 'a') { ok = 0; break; }
	if (ok) ans += dfs(U0, z+1, top);
	return ans % P;
}
int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s); m = strlen(s);
	scanf("%s", t);
	bas2[0] = ibas2[0] = 1;
	for (int i = 1; i <= n; i++) bas2[i] = 2*bas2[i-1]%P, ibas2[i] = 1LL*inv2*ibas2[i-1]%P;
	for (int i = 1; i <= n; i++) {
		(suf[i][t[i-1] - 'a'] += ibas2[i]) %= P;
		for (int j = 0; j < 26; j++) (suf[i][j] += suf[i-1][j]) %= P;
	}
	while (q--) {
		int ans = 0;
		scanf("%d%s", &idx, w); T = strlen(w);
		for (int i = 0; i <= m; i++) {
			int ok = 1;
			for (int j = 0; j < T; j++)
				if ((j+i)%(m+1) != m && w[j] != s[(j+i)%(m+1)]) { ok = 0; break; }
			if (!ok) continue;
			String _w;
			for (int j = 0; j < T; j++)
				if ((j+i)%(m+1) == m) _w.push_back(w[j] - 'a');
			if (!_w.size()) (ans += bas2[idx]) %= P;
			else (ans += dfs(_w, 0, idx)) %= P;
		}
		printf("%d\n", ans);
	}
	return 0;
}