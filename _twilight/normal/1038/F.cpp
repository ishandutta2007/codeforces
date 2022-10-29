#include <bits/stdc++.h>
#ifndef local
#define Auto "%I64d"
#else
#define Auto "%lld"
#endif
using namespace std;
typedef bool boolean;

const int N = 42;

#define ll long long

int n, m;
char s[N];
int fail[N];
int nxt[N][2];
vector<int> prv[N][2];
ll f[N][N], g[N][N];

void kmp() {
	fail[0] = fail[1] = 0;
	for (int i = 1, j; i < m; i++) {
		j = fail[i];
		while (j && s[i + 1] != s[j + 1])
			j = fail[j];
		fail[i + 1] = ((s[i + 1] == s[j + 1]) ? (j + 1) : (0));
	}
}

void build() {
	for (int i = 0; i <= m; i++) {
		for (int c = 0; c < 2; c++) {
			int j = i;
			while (j && s[j + 1] != c)
				j = fail[j];
			nxt[i][c] = ((s[j + 1] == c) ? (j + 1) : (0));
			prv[nxt[i][c]][c].push_back(i);
		}
	}
}

int main() {
	scanf("%d%s", &n, s + 1);
	m = strlen(s + 1);
	for (int i = 1; i <= m; i++) {
		s[i] -= '0';
	}
	s[0] = s[m + 1] = -1;
	kmp();
	build();
	f[0][m] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ll v = f[i - 1][j];
			if (!v) continue;
			for (int c = 0; c < 2; c++) {
				for (auto e : prv[j][c]) {
					if (e != m) {
						f[i][e] += v;
					}
				}
			}
		}
	} 
	g[0][m] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ll v = g[i - 1][j];
			if (!v)  continue;
			for (int c = 0; c < 2; c++) {
				g[i][nxt[j][c]] += v;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			ans += f[i][j] * g[n - i][j];
		}
	}
	printf(Auto"\n", ans);
	return 0;
}