#include <bits/stdc++.h>

const int N = 5005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
int a[N];
long long sum[N];

struct Hole {
	int x, c;

	bool operator < (const Hole &rhs) const {
		return x < rhs.x;
	}
} b[N];

long long f[N][N];

struct Queue {
	int h, t;
	std::pair<int, long long> Q[N];

	void clear() {
		h = 1, t = 0;
	}

	void push(std::pair<int, long long> v) {
		while (h <= t && v.second <= Q[t].second) {
			--t;
		}
		Q[++t] = v;
	}

	std::pair<int, long long> top(int p) {
		while (h <= t && Q[h].first < p) {
			++h;
		}
		if (h <= t) {
			return Q[h];
		} else {
			return {-1, INF};
		}
	}
} Q1, Q2;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= m; ++i) {
		std::cin >> b[i].x >> b[i].c;
	}
	std::sort(b + 1, b + 1 + m);
	for (int i = 1; i <= n; ++i) {
		f[0][i] = INF;
	}
	f[0][0] = 0;
	for (int i = 1; i <= m; ++i) {
		int t = std::upper_bound(a + 1, a + 1 + n, b[i].x) - a - 1;
		Q1.clear(), Q2.clear();
		for (int j = 0; j <= n; ++j) {
			f[i][j] = f[i - 1][j];
			long long v1 = Q1.top(j - b[i].c).second;
			long long v2 = Q2.top(j - b[i].c).second;
			if (v1 < INF) {
				int p = std::min(t, j);
				f[i][j] = std::min(f[i][j], v1 + sum[j] - 2 * sum[p] + 1ll * (2 * p - j) * b[i].x);
			}
			if (v2 < INF) {
				f[i][j] = std::min(f[i][j], v2 + sum[j] - 1ll * j * b[i].x);
			}
			if (f[i - 1][j] < INF) {
				if (j <= t) {
					Q1.push({j, f[i - 1][j] + sum[j] - 1ll * j * b[i].x});
				} else {
					Q2.push({j, f[i - 1][j] + 1ll * j * b[i].x - sum[j]});
				}
			}
		}
	}
	if (f[m][n] < INF) {
		std::cout << f[m][n] << std::endl;
	} else {
		std::cout << -1 << std::endl;
	}
}