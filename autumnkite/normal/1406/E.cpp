#include <bits/stdc++.h>

std::vector<int> init_prime(int n) {
	std::vector<bool> vis(n + 1);
	std::vector<int> prime;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
		}
		for (int x : prime) {
			if (x * i > n) {
				break;
			}
			vis[x * i] = true;
			if (i % x == 0) {
				break;
			}
		}
	}
	return prime;
}

int query(int x) {
	std::cout << "A " << x << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void erase(int x) {
	std::cout << "B " << x << std::endl;
	int res;
	std::cin >> res;
}

void answer(int x) {
	std::cout << "C " << x << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> prime(init_prime(n));
	int pos = 0;
	while (pos < (int)prime.size() && 1ll * prime[pos] * prime[pos] <= n) {
		++pos;
	}
	std::vector<int> p(prime.begin(), prime.begin() + pos);
	std::vector<int> q(prime.begin() + pos, prime.end());

	for (int x : p) {
		erase(x);
	}
	int ans = 1;
	for (int x : p) {
		int v = x;
		while (v <= n && query(v)) {
			ans *= x;
			v *= x;
		}
	}

	if (ans == 1) {
		int B = (int)sqrt(q.size()) + 1;
		int lst = 0;
		for (int i = 0; i <= (int)q.size(); ++i) {
			if (i > 0 && (i % B == 0 || i == (int)q.size())) {
				if (query(1) > (int)q.size() - i + 1) {
					for (int j = lst; j < i; ++j) {
						if (query(q[j])) {
							ans *= q[j];
							break;
						}
					}
					break;
				}
				lst = i;
			}
			if (i < (int)q.size()) {
				erase(q[i]);
			}
		}
		answer(ans);
	} else {
		for (int x : q) {
			if (query(x) > 1) {
				ans *= x;
			}
		}
		answer(ans);
	}
}