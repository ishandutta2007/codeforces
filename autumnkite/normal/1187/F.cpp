#include <bits/stdc++.h>

const int P = 1000000007;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> l(n + 1), r(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> l[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> r[i];
		++r[i];
	}
	l[n] = 0, r[n] = 1;

	auto solve = [&](std::vector<int> l, std::vector<int> r) {
		int len = *std::min_element(r.begin(), r.end()) - *std::max_element(l.begin(), l.end());
		len = std::max(len, 0);
		int prod = 1;
		for (int i = 0; i < (int)l.size(); ++i) {
			prod = 1ll * prod * (r[i] - l[i]) % P;
		}
		return 1ll * len * qpow(prod, P - 2) % P;
	};

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (1 + P - solve({l[i], l[i + 1]}, {r[i], r[i + 1]})) % P;
	}
	int sum = 0;
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = (ans + 1ll * sum * a[i]) % P;
		sum = (sum + a[i - 1]) % P; 
	}
	for (int i = 1; i < n; ++i) {
		ans = (ans + 1ll + 
		       P - solve({l[i - 1], l[i]}, {r[i - 1], r[i]}) + 
		       P - solve({l[i], l[i + 1]}, {r[i], r[i + 1]}) + 
		       solve({l[i - 1], l[i], l[i + 1]}, {r[i - 1], r[i], r[i + 1]})) % P;
	}
	std::cout << (2ll * ans + std::accumulate(a.begin(), a.end(), 0ll)) % P << "\n";
}