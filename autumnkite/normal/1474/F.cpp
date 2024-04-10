#include <bits/stdc++.h>

const int P = 998244353;

typedef std::vector<std::vector<int>> matrix;

matrix operator*(const matrix &A, const matrix &B) {
	matrix res(A.size(), std::vector<int>(B[0].size()));
	for (int i = 0; i < (int)A.size(); ++i) {
		for (int k = i; k < (int)B.size(); ++k) {
			for (int j = k; j < (int)B[0].size(); ++j) {
				res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j]) % P;
			}
		}
	}
	return res;
}

std::vector<int> operator*(const std::vector<int> &A, const matrix &B) {
	std::vector<int> res(A.size());
	for (int i = 0; i < (int)A.size(); ++i) {
		for (int j = 0; j < (int)A.size(); ++j) {
			res[j] = (res[j] + 1ll * A[i] * B[i][j]) % P;
		}
	}
	return res;
}

matrix qpow(matrix a, long long b) {
	matrix s(a.size(), std::vector<int>(a.size()));
	for (int i = 0; i < (int)a.size(); ++i) {
		s[i][i] = 1;
	}
	for (; b; b >>= 1) {
		if (b & 1) {
			s = s * a;
		}
		a = a * a;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int x;
	std::cin >> x;
	std::vector<long long> d;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		if (v == 0) {
			continue;
		}
		if (!d.empty() && (v > 0) == (d.back() > 0)) {
			d.back() += v;
		} else {
			d.push_back(v);
		}
	}
	n = d.size();

	std::vector<long long> v(n + 1);
	for (int i = 0; i < n; ++i) {
		v[i + 1] = v[i] + d[i];
	}
	long long LIS = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			LIS = std::max(LIS, v[j] - v[i] + 1);
		}
	}

	if (LIS == 1) {
		int ans = 1;
		for (int i = 0; i < n; ++i) {
			ans = (ans + abs(d[i])) % P;
		}
		std::cout << LIS << " " << ans << "\n";
		return 0;
	}

	auto calc = [&](std::vector<long long> v) -> int {
		int n = (int)v.size() - 1;
		std::vector<long long> L(n + 1), R(n + 1);
		for (int i = 0; i < n; ++i) {
			if (v[i] < v[i + 1]) {
				L[i] = v[i], R[i] = v[i + 1];
			} else {
				L[i] = v[i + 1] + 1, R[i] = v[i] + 1;
			}
		}
		L[n] = v[n], R[n] = v[n] + 1;

		std::vector<long long> p;
		for (int i = 0; i <= n; ++i) {
			p.push_back(v[i] - 1);
			p.push_back(v[i]);
			p.push_back(v[i] + 1);
		}
		std::sort(p.begin(), p.end());
		p.erase(std::unique(p.begin(), p.end()), p.end());

		std::vector<int> s(n + 1, 0);
		for (int i = 0; i <= n; ++i) {
			s[i] = L[i] <= v[0] && v[0] < R[i];
		}
		for (int k = 0; k < (int)p.size() - 1; ++k) {
			long long l = p[k], r = p[k + 1];
			if (r <= v[0] || l >= v[n]) {
				continue;
			}
			matrix A(n + 1, std::vector<int>(n + 1, 0));
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (L[i] <= l && l < R[i] && L[j] <= l + 1 && l + 1 < R[j]) {
						A[i][j] = 1;
					}
				}
				if (v[i + 1] > v[i] && L[i] <= l && l + 1 < R[i]) {
					A[i][i] = 1;
				}
			}
			s = s * qpow(A, r - l);
		}
		int res = 0;
		for (int i = 0; i <= n; ++i) {
			if (L[i] <= v[n] && v[n] < R[i]) {
				res = (res + s[i]) % P;
			}
		}
		return res;
	};

	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int r = i;
		for (int j = i; j <= n; ++j) {
			if (v[j] - v[i] + 1 == LIS) {
				r = j;
			}
		}
		if (v[r] - v[i] + 1 == LIS) {
			ans = (ans + calc(std::vector<long long>(v.begin() + i, v.begin() + r + 1))) % P;
			i = r;
		}
	}
	std::cout << LIS << " " << ans << "\n";
}