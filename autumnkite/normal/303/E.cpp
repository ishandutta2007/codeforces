#include <bits/stdc++.h>

const int N = 85;

int n;
int m, x[N << 1];

struct Node {
	int l, r;
} a[N];

int len[N];

double f[N][N], ans[N][N];

void add(int q, int c, int i) {
	for (int j = c; ~j; --j) {
		for (int k = c - j; ~k; --k) {
			double s = 0;
			if (c - j - k && q < a[i].r) {
				int t = x[a[i].r] - x[std::max(q + 1, a[i].l)];
				s += f[j][k] * t / len[i];
			}
			if (j && a[i].l <= q) {
				int t = x[std::min(q, a[i].r)] - x[a[i].l];
				s += f[j - 1][k] * t / len[i];
			}
			if (k && a[i].l <= q && q < a[i].r) {
				s += f[j][k - 1] * (x[q + 1] - x[q]) / len[i];
			}
			f[j][k] = s;
		}
	}
}

void solve(int l, int r, int q, int c) {
	if (l == r) {
		if (a[l].l <= q && q < a[l].r) {
			for (int j = 0; j <= c; ++j) {
				for (int k = 0; k <= c - j; ++k) {
					double t = f[j][k] * (x[q + 1] - x[q]) / len[l] / (k + 1);
					ans[l][j + 1] += t, ans[l][j + k + 2] -= t;
				}
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	double tmp[N][N];
	for (int j = 0; j < n; ++j) {
		for (int k = 0; k < n; ++k) {
			tmp[j][k] = f[j][k];
		}
	}
	int nc = c;
	for (int i = l; i <= mid; ++i) {
		add(q, ++nc, i);
	}
	solve(mid + 1, r, q, nc);
	for (int j = 0; j < n; ++j) {
		for (int k = 0; k < n; ++k) {
			f[j][k] = tmp[j][k];
		}
	}
	nc = c;
	for (int i = mid + 1; i <= r; ++i) {
		add(q, ++nc, i);
	}
	solve(l, mid, q, nc);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].l >> a[i].r;
		x[++m] = a[i].l;
		x[++m] = a[i].r;
		len[i] = a[i].r - a[i].l;
	}
	std::sort(x + 1, x + m + 1);
	m = std::unique(x + 1, x + m + 1) - x - 1;
	for (int i = 1; i <= n; ++i) {
		a[i].l = std::lower_bound(x + 1, x + m + 1, a[i].l) - x;
		a[i].r = std::lower_bound(x + 1, x + m + 1, a[i].r) - x;
	}

	for (int q = 1; q < m; ++q) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				f[j][k] = 0;
			}
		}
		f[0][0] = 1;
		solve(1, n, q, 0);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans[i][j] += ans[i][j - 1];
			std::cout << ans[i][j] << " ";
		}
		std::cout << std::endl;
	}
}