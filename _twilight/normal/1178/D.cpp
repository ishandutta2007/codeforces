#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

const int N = 1003, M = 10005;

int num = 0;
int pri[M];
boolean vis[M];
void Euler(int n) {
	vis[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			pri[num++] = i;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			vis[x] = true;
			if (!(i % *p)) {
				break;
			}
		}
	}
}

int n;
int f[N][M << 1], g[N][M << 1];
boolean dfs(int n, int m) {
	if (!n)
		return !m;
	if (f[n][m] != -1)
		return f[n][m];
	f[n][m] = false;
	for (int *p = pri; *p <= m && *p < ::n && !f[n][m]; p++) {
		f[n][m] |= dfs(n - 1, m - *p);
		if (f[n][m]) {
			g[n][m] = *p;
		}
	}
	return f[n][m];
}

vector<int> d;
void travel(int n, int m) {
	if (!n)
		return;
	travel(n - 1, m - g[n][m]);
	d.push_back(g[n][m]);
}

vector<pii> D;
int main() {
	scanf("%d", &n);
	if (n <= 2) {
		puts("-1");
		return 0;
	}
	Euler(10000);
	memset(f, -1, sizeof(f));
	for (int *p = pri, *_ = pri + num; p != _ && *p <= n * (n - 1) / 2; p++) {
		if (*p >= n && dfs(n, *p << 1)) {
			travel(n, *p << 1);
			printf("%d\n", *p);
			for (int i = 0; i < n; i++) {
				D.emplace_back(d[i], i + 1);
			}			
			while (!D.empty()) {
				sort(D.begin(), D.end());
				pii e = D.back();
				D.pop_back();
				for (int i = 1; i <= e.first; i++) {
					printf("%d %d\n", e.second, D[D.size() - i].second);
					D[D.size() - i].first--;
				}
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}