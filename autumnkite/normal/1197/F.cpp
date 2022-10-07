#include <bits/stdc++.h>

const int N = 1005, M = 1 << 6, LG = 30, P = 998244353;

typedef std::vector<std::vector<int>> matrix;

int n, len[N], m;
int can[3][3];
std::vector<std::pair<int, int>> pos[N];

int trans[M][3];
matrix pw[30];

matrix operator * (const matrix &A, const matrix &B) {
	matrix res(A.size(), std::vector<int>(B[0].size()));
	for (int i = 0; i < (int)A.size(); ++i) {
		for (int k = 0; k < (int)B.size(); ++k) {
			for (int j = 0; j < (int)B[0].size(); ++j) {
				res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j]) % P;
			}
		}
	}
	return res;
}

int f[N][4];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> len[i];
	}
	std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		int x, p, c;
		std::cin >> x >> p >> c;
		--c;
		pos[x].push_back({p, c});
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cin >> can[i][j];
		}
	}

	for (int S = 0; S < M; ++S) {
		for (int c = 0; c < 3; ++c) {
			int vis[4];
			for (int i = 0; i < 4; ++i) {
				vis[i] = 0;
			}
			for (int i = 0; i < 3; ++i) {
				if (can[c][i]) {
					vis[S >> (i * 2) & 3] = 1;
				}
			}
			int x = 0;
			while (vis[x]) {
				++x;
			}
			trans[S][c] = (S << 2 | x) & (M - 1);
		}
	}

	matrix A(M, std::vector<int>(M));
	for (int i = 0; i < M; ++i) {
		for (int c = 0; c < 3; ++c) {
			int j = trans[i][c];
			++A[i][j]; 
		}
	}
	pw[0] = A;
	for (int i = 1; i < LG; ++i) {
		pw[i] = pw[i - 1] * pw[i - 1];
	}

	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		std::sort(pos[i].begin(), pos[i].end());
		matrix st(1, std::vector<int>(M));
		st[0][3 << 4 | 3 << 2 | 3] = 1;
		int lst = 0;
		for (auto p : pos[i]) {
			int x = p.first, c = p.second;
			int b = x - lst - 1;
			for (int j = 0; j < LG; ++j) {
				if (b >> j & 1) {
					st = st * pw[j];
				}
			}
			std::vector<int> tmp(M);
			for (int S = 0; S < M; ++S) {
				int T = trans[S][c];
				tmp[T] = (tmp[T] + st[0][S]) % P;
			}
			st[0].swap(tmp);
			lst = x;
		}
		int b = len[i] - lst;
		for (int j = 0; j < LG; ++j) {
			if (b >> j & 1) {
				st = st * pw[j];
			}
		}
		std::vector<int> a(4);
		for (int S = 0; S < M; ++S) {
			a[S & 3] = (a[S & 3] + st[0][S]) % P;
		}
		for (int S = 0; S < 4; ++S) {
			for (int T = 0; T < 4; ++T) {
				f[i][S] = (f[i][S] + 1ll * f[i - 1][T] * a[S ^ T]) % P;
			}
		}
	}
	std::cout << f[n][0] << "\n";
}