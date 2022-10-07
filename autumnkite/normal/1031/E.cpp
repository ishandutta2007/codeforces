#include <bits/stdc++.h>

const int N = 100005, INF = 0x3f3f3f3f;

struct State {
	int d;
	int x, y, z;
} f[1 << 12];

void BFS(int n) {
	for (int i = 0; i < (1 << n); ++i) {
		f[i].d = INF;
	}
	std::vector<int> Q;
	f[0] = {0, 0, 0, 0};
	Q.push_back(0);
	for (int i = 0; i < (int)Q.size(); ++i) {
		int S = Q[i];
		for (int j = 0; j < n; ++j) {
			for (int k = 1; k <= std::min(j, n - 1 - j); ++k) {
				int x = j - k, y = j, z = j + k;
				int T = S ^ (1 << x) ^ (1 << y) ^ (1 << z);
				if (f[T].d < INF) {
					continue;
				}
				f[T] = {f[S].d + 1, x, y, z};
				Q.push_back(T);
			}
		}
	}
}

int st[1 << 6];

int n, a[N];

struct Operation {
	int x, y, z;
};

std::vector<Operation> ans;

void getAns(int k, int S) {
	while (S != 0) {
		ans.push_back({k + f[S].x, k + f[S].y, k + f[S].z});
		a[k + f[S].x] ^= 1;
		a[k + f[S].y] ^= 1;
		a[k + f[S].z] ^= 1;
		S ^= (1 << f[S].x) ^ (1 << f[S].y) ^ (1 << f[S].z);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	BFS(12);
	for (int i = 0; i < (1 << 6); ++i) {
		st[i] = i;
		for (int j = 0; j < (1 << 6); ++j) {
			int S = j << 6 | i;
			if (f[S].d < f[st[i]].d) {
				st[i] = S;
			}
		}
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int k = 0;
	while (n - k >= 12) {
		int S = 0;
		for (int i = 0; i < 6; ++i) {
			S |= a[k + i] << i;
		}
		getAns(k, st[S]);
		k += 6;
	}

	k = std::min(k, std::max(0, n - 8));
	BFS(n - k);
	int S = 0;
	for (int i = 0; i < n - k; ++i) {
		S |= a[k + i] << i;
	}
	if (f[S].d == INF) {
		std::cout << "NO\n";
		return 0;
	}
	getAns(k, S);
	std::cout << "YES\n";
	std::cout << ans.size() << "\n";
	for (auto v : ans) {
		std::cout << v.x + 1 << " " << v.y + 1 << " " << v.z + 1 << "\n";
	}
}