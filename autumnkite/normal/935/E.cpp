#include <bits/stdc++.h>

const int N = 10005, INF = 0x3f3f3f3f;

int n;
char a[N];
int P, M;
bool isP;

int top, sta[N];
int m, ls[N], rs[N];

int f[N][105], g[N][105];

void dfs(int u) {
	if (!ls[u] || !rs[u]) {
		return;
	}
	dfs(ls[u]), dfs(rs[u]);
	for (int i = 0; i <= std::min(P, M); ++i) {
		f[u][i] = -INF;
		g[u][i] = INF;
	}
	for (int i = 0; i <= std::min(P, M); ++i) {
		for (int j = 0; i + j + isP <= std::min(P, M); ++j) {
			f[u][i + j + isP] = std::max(f[u][i + j + isP], f[ls[u]][i] + f[rs[u]][j]);
			g[u][i + j + isP] = std::min(g[u][i + j + isP], g[ls[u]][i] + g[rs[u]][j]);
		}
	}
	for (int i = 0; i <= std::min(P, M); ++i) {
		for (int j = 0; i + j + !isP <= std::min(P, M); ++j) {
			f[u][i + j + !isP] = std::max(f[u][i + j + !isP], f[ls[u]][i] - g[rs[u]][j]);
			g[u][i + j + !isP] = std::min(g[u][i + j + !isP], g[ls[u]][i] - f[rs[u]][j]);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> (a + 1);
	n = strlen(a + 1);
	
	std::cin >> P >> M;
	isP = (P <= M);
	
	for (int i = 1; i <= n; ++i) {
		if (isdigit(a[i])) {
			++m;
			f[m][0] = g[m][0] = a[i] - '0';
			for (int j = 1; j <= std::min(P, M); ++j) {
				f[m][j] = -INF;
				g[m][j] = INF;
			}
			sta[++top] = m;
		} else if (a[i] == ')') {
			++m;
			ls[m] = sta[top - 1], rs[m] = sta[top];
			top -= 2;
			sta[++top] = m;
		}
	}
	
	dfs(sta[1]);
	std::cout << f[sta[1]][std::min(P, M)] << "\n";
}