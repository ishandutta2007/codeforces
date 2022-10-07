#include <bits/stdc++.h>

long long area(int i, int j, int k) {
	std::cout << "1 " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
	long long res;
	std::cin >> res;
	return res;
}

int sign(int i, int j, int k) {
	std::cout << "2 " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
	int res;
	std::cin >> res;
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	int id = 1;
	for (int i = 2; i < n; ++i) {
		if (sign(0, id, i) < 0) {
			id = i;
		}
	}

	std::vector<std::pair<long long, int>> s;
	for (int i = 1; i < n; ++i) {
		if (i != id) {
			s.emplace_back(area(0, id, i), i);
		}
	}
	std::sort(s.begin(), s.end());

	std::deque<int> Q;
	int h = s.back().second;
	Q.push_back(h);
	for (int i = (int)s.size() - 2; i >= 0; --i) {
		if (sign(0, s[i].second, h) > 0) {
			Q.push_front(s[i].second);
		} else {
			Q.push_back(s[i].second);
		}
	}
	Q.push_front(id);
	Q.push_front(0);
	
	std::cout << "0 ";
	for (int v : Q) {
		std::cout << v + 1 << " ";
	}
	std::cout << "\n";
}