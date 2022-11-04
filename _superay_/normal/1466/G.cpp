#include <bits/stdc++.h>
using namespace std;
const int md[3] = {998244353, 1000000007, 1000000009};
struct II {
	int x[3];
	inline II(int a = 0) {
		x[0] = x[1] = x[2] = a;
	}
	inline II(int a, int b, int c) {
		x[0] = a, x[1] = b, x[2] = c;
	}
	inline bool operator == (const II &oth) const {
		return x[0] == oth.x[0] && x[1] == oth.x[1] && x[2] == oth.x[2];
	}
	inline II operator + (const II &oth) const {
		return II((x[0] + oth.x[0]) % md[0],
		(x[1] + oth.x[1]) % md[1],
		(x[2] + oth.x[2]) % md[2]);
	}
	inline II operator - (const II &oth) const {
		return II((x[0] + md[0] - oth.x[0]) % md[0],
		(x[1] + md[1] - oth.x[1]) % md[1],
		(x[2] + md[2] - oth.x[2]) % md[2]);
	}
	inline II operator * (const II oth) const {
		return II(1ll * x[0] * oth.x[0] % md[0],
		1ll * x[1] * oth.x[1] % md[1],
		1ll * x[2] * oth.x[2] % md[2]);
	}
} bs(1145141, 1919810, 1233211);
const int mod = 1000000007;
const int N = 1000005;
int n, q, lim, sl[20], ps[N][26], ipw2[N], pw2[N];
II phs[N], shs[N], pw[N], pcs[N], scs[N];
char s[20][N], t[N], cur[N];
int main() {
	pw[0] = II(1);
	for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * bs;
	ipw2[0] = pw2[0] = 1;
	for (int i = 1; i < N; i++) {
		pw2[i] = 2 * pw2[i - 1] % mod;
		ipw2[i] = (ipw2[i - 1] % 2 == 1 ? (ipw2[i - 1] + mod) : ipw2[i - 1]) / 2;
	}
	scanf("%d%d %s %s", &n, &q, s[0] + 1, t + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) ps[i][j] = ps[i - 1][j];
		int c = t[i] - 'a';
		ps[i][c] = (ps[i][c] + ipw2[i]) % mod;
	}
	sl[0] = strlen(s[0] + 1);
	for (int i = 1; i < 20; i++) sl[i] = sl[i - 1] * 2 + 1;
	for (int i = 1; i < 20; i++) if (sl[i] > 1000000) {
		lim = i - 1;
		break;
	}
	lim = min(n, lim);
	for (int i = 1; i <= lim; i++) {
		for (int j = 1; j <= sl[i - 1]; j++) s[i][j] = s[i][sl[i - 1] + 1 + j] = s[i - 1][j];
		s[i][sl[i - 1] + 1] = t[i];
	}
	for (int i = 1; i <= sl[lim]; i++) {
		phs[i] = phs[i - 1] + pw[i] * II(s[lim][i]);
	}
	for (int i = sl[lim]; i >= 1; i--) {
		shs[i] = shs[i + 1] * bs + II(s[lim][i]) * bs;
	}
	while (q--) {
		int k, l;
		scanf("%d %s", &k, cur + 1);
		l = strlen(cur + 1);
		pcs[0] = scs[l + 1] = II(0);
		for (int i = 1; i <= l; i++) {
			pcs[i] = pcs[i - 1] + pw[i] * II(cur[i]);
		}
		for (int i = l; i >= 1; i--) {
			scs[i] = scs[i + 1] * bs + II(cur[i]) * bs;
		}
		int ans = 0;
		for (int i = 1; i <= l; i++) {
			int cl = max(i - 1, l - i), c = cur[i] - 'a';
			if (cl <= sl[lim] && pcs[i - 1] == shs[sl[lim] - i + 2] && scs[i + 1] == phs[l - i]) {
				int j = lower_bound(sl, sl + 1 + lim, cl) - sl;
				if (j <= k) {
					ans = (ans + 1ll * pw2[k] * (ps[k][c] + mod - ps[j][c])) % mod;
				}
			}
		}
		if (l <= sl[0]) {
			int cc = 0;
			for (int i = 1; i + l - 1 <= sl[0]; i++) {
				if (phs[i + l - 1] - phs[i - 1] == pcs[l] * pw[i - 1]) cc++;
			}
			if (cc) ans = (ans + 1ll * cc * pw2[k]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}