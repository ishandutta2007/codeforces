#include <bits/stdc++.h>

int query(std::vector<int> A, std::vector<int> B) {
	std::cout << "? " << A.size() << " " << B.size() << "\n";
	for (int x : A) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
	for (int x : B) {
		std::cout << x + 1 << " ";
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	return x;
}

int solve(std::vector<int> S, int x) {
	if ((int)S.size() == 1) {
		return S[0];
	}
	int mid = S.size() / 2;
	if (query(std::vector<int>(S.begin(), S.begin() + mid), {x})) {
		return solve(std::vector<int>(S.begin(), S.begin() + mid), x);
	} else {
		return solve(std::vector<int>(S.begin() + mid, S.end()), x);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> id(1, 0);
		int p = 1;
		while (!query(id, {p})) {
			id.push_back(p);
			++p;
		}
		std::vector<int> ans;
		for (int i = p + 1; i < n; ++i) {
			if (!query(id, {i})) {
				ans.push_back(i);
			}
		}
		int pos = solve(id, p);
		for (int i : id) {
			if (i != pos) {
				ans.push_back(i);
			}
		}
		std::cout << "! " << ans.size() << " ";
		for (int x : ans) {
			std::cout << x + 1 << " ";
		}
		std::cout << std::endl;
	}
}