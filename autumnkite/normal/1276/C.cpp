#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	std::vector<int> v(a);
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	std::vector<int> cnt(v.size());
	for (int &x : a) {
		x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
		++cnt[x];
	}

	std::vector<int> ccnt(n + 1);
	for (int x : cnt) {
		++ccnt[x];
	}
	int sum = 0, d = cnt.size();
	int ansp = 0, ansq = 0;
	for (int p = 1; p * p <= n; ++p) {
		sum += d;
		d -= ccnt[p];
		int q = sum / p;
		if (p <= q) {
			if (p * q > ansp * ansq) {
				ansp = p, ansq = q;
			}
		}
	}

	std::cout << ansp * ansq << "\n";
	std::cout << ansp << " " << ansq << "\n";
	std::vector<std::vector<int>> mat(ansp, std::vector<int>(ansq));
	int idx = 0;
	std::vector<std::pair<int, int>> val;
	for (int i = 0; i < (int)v.size(); ++i) {
		val.emplace_back(std::min(ansp, cnt[i]), v[i]);
	}
	std::sort(val.begin(), val.end());
	std::reverse(val.begin(), val.end());
	for (auto [c, v] : val) {
		for (int i = 0; i < c; ++i) {
			mat[idx % ansp][(idx / ansp + idx % ansp) % ansq] = v;
			++idx;
		}
	}
	for (int i = 0; i < ansp; ++i) {
		for (int j = 0; j < ansq; ++j) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}
}