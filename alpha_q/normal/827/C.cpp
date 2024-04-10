#include <bits/stdc++.h>

using namespace std;

const int K = 12;
const int N = 100004;

int q, n;
char s[N], t[K], c[3];
int f[4][K][K][N];
map <char, int> to;

void update (int fenw[], int p, int v) {
	while (p < N) fenw[p] += v, p += p & -p;
}

int query (int fenw[], int p) {
	int sum = 0;
	while (p > 0) sum += fenw[p], p -= p & -p;
	return sum;
}

int range (int fenw[], int l, int r) {
	return query(fenw, r) - query(fenw, l - 1);
}

int main() {
	to['A'] = 0, to['C'] = 1, to['G'] = 2, to['T'] = 3;
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			for (int k = i; k < n; k += j) {
				update(f[to[s[k]]][i][j], k + 1, 1);
			}
		}
	}
	scanf("%d", &q);
	while (q--) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			int x, y, z;
			scanf("%d %s", &x, c);
			--x;
			y = to[s[x]];
			z = to[c[0]];
			s[x] = c[0];
			for (int i = 0; i < 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					if (x >= i and (x - i) % j == 0) {
						update(f[y][i][j], x + 1, -1);
						update(f[z][i][j], x + 1, 1);
					}
				}
			}
		} else {
			int l, r, sz;
			scanf("%d %d %s", &l, &r, t);
			--l, --r, sz = strlen(t);
			sz = min(sz, r - l + 1);
			int ans = 0;
			for (int i = 0, j = l % sz; i < sz; ++i) {
				int cur = to[t[i]];
				ans += range(f[cur][j][sz], l + 1, r + 1);
				++j;
				if (j == sz) j = 0;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}