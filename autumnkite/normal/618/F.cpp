#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<long long> sa(n + 1), sb(n + 1);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		sa[i + 1] = sa[i] + x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		sb[i + 1] = sb[i] + x;
	}

	bool swapped = false;
	if (sa[n] > sb[n]) {
		sa.swap(sb);
		swapped = true;
	}

	std::vector<std::pair<int, int>> pos(n, std::make_pair(-1, -1));
	int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
	for (int i = 0, j = 0; i <= n; ++i) {
		while (j < n && sb[j + 1] <= sa[i]) {
			++j;
		}
		int v = sa[i] - sb[j];
		if (pos[v].first == -1) {
			pos[v] = std::make_pair(i, j);
		} else {
			l1 = pos[v].first, l2 = pos[v].second;
			r1 = i, r2 = j;
			break;
		}
	}

	if (l1 == -1) {
		std::cout << -1 << "\n";
		return 0;
	}
	if (swapped) {
		std::swap(l1, l2);
		std::swap(r1, r2);
	}

	std::cout << r1 - l1 << "\n";
	for (int i = l1; i < r1; ++i) {
		std::cout << i + 1 << " \n"[i + 1 == r1];
	}
	std::cout << r2 - l2 << "\n";
	for (int i = l2; i < r2; ++i) {
		std::cout << i + 1 << " \n"[i + 1 == r2];
	}
}