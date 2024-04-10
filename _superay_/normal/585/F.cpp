#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline void Add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int go[2005][10], pre[2005], len[2005], tot = 1, id[2005][55], good[110000], cnt, trans[110000][10];
inline int ext(int p, int x) {
	int np = ++tot;
	len[np] = len[p] + 1;
	while (p && !go[p][x]) {
		go[p][x] = np;
		p = pre[p];
	}
	if (!p) pre[np] = 1;
	else {
		int q = go[p][x];
		if (len[q] == len[p] + 1) pre[np] = q;
		else {
			int nq = ++tot;
			len[nq] = len[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			pre[nq] = pre[q];
			pre[np] = pre[q] = nq;
			while (p && go[p][x] == q) {
				go[p][x] = nq;
				p = pre[p];
			}
		}
	}
	return np;
}
int n, d, f[2][110000][2][2][2];
char s[1005], x[55], y[55];
int main() {
	scanf(" %s %s %s", s + 1, x + 1, y + 1);
	n = strlen(s + 1);
	d = strlen(x + 1);
	len[0] = -1;
	for (int i = 1, lst = 1; i <= n; i++) lst = ext(lst, s[i] - '0');
	for (int i = 1; i <= tot; i++) {
		for (int j = len[pre[i]] + 1; j <= min(d, len[i]); j++) {
			good[id[i][j] = ++cnt] = (j >= (d / 2));
		}
	}
	for (int i = 1; i <= tot; i++) {
		for (int c = 0; c < 10; c++) {
			int u = i, flag, tl = 0;
			if (go[u][c]) {
				flag = 0;
				u = go[u][c];
			} else {
				while (u != 1 && !go[u][c]) u = pre[u];
				if (!go[u][c]) {
					flag = 1;
					tl = 0;
				} else {
					flag = 2;
					tl = len[u] + 1;
					u = go[u][c];
				}
			}
			for (int j = len[pre[i]] + 1; j <= min(d, len[i]); j++) {
				if (!flag) tl = j + 1;
				if (tl <= d) trans[id[i][j]][c] = id[u][tl];
			}
		}
	}
	int cur = 0, lst = 1;
	f[cur][id[1][0]][0][1][1] = 1;
	for (int i = 1; i <= d; i++) {
		swap(cur, lst);
		memset(f[cur], 0, sizeof(f[cur]));
		for (int j = 1; j <= cnt; j++) {
			for (int ig = 0; ig < 2; ig++) {
				for (int fl = 0; fl < 2; fl++) {
					for (int fr = 0; fr < 2; fr++) {
						if (!f[lst][j][ig][fl][fr]) continue;
						int curl = (fl ? x[i] - '0' : 0);
						int curr = (fr ? y[i] - '0' : 9);
						for (int c = curl; c <= curr; c++) {
							Add(f[cur][trans[j][c]][ig | good[trans[j][c]]][fl & (c == curl)][fr & (c == curr)], f[lst][j][ig][fl][fr]);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= cnt; j++) {
		for (int fl = 0; fl < 2; fl++) {
			for (int fr = 0; fr < 2; fr++) {
				Add(ans, f[cur][j][1][fl][fr]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}