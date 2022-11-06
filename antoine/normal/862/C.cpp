#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

// long long !!!
int n, x;
std::set<int> ans;

void g() {
	int i = 4;
	while (ans.size() != n) {
		if (!ans.count(i) && !ans.count(i + 1) && !ans.count(i + 2) && !ans.count(i + 3)) {
			ans.insert(i);
			ans.insert(i + 1);
			ans.insert(i + 2);
			ans.insert(i + 3);
		}
		i += 4;
	}
}

void f() {
	if (n % 4 == 1)
		ans.insert(x);
	else if (x == 0) {
		if (n % 4 == 2) {
			if (n == 2) {
				std::cout << "NO";
				exit(0);
			}
			ans.insert(1);
			ans.insert(2);
			ans.insert(3);
			ans.insert(1 << 4);
			ans.insert(2 << 4);
			ans.insert(3 << 4);
		}
		else if (n % 4 == 3) {
			ans.insert(1);
			ans.insert(2);
			ans.insert(3);
		}
	} else if (n % 4 == 2) {
		ans.insert(0);
		ans.insert(x);
	} else if (x == 1) {
		if (n % 4 == 3) {
			ans.insert(0);
			ans.insert(2);
			ans.insert(3);
		}
		else if (n % 4 == 0) {
			ans.insert(2);
			ans.insert(4);
			ans.insert(6);
			ans.insert(1);
		}
	}
	else {
		if (n % 4 == 3) {
			ans.insert(0);
			ans.insert(1);
			ans.insert(x ^ 1);
		}
		else if (n % 4 == 0) {
			if (x > 3) {
				ans.insert(x);
				ans.insert(1);
				ans.insert(2);
				ans.insert(3);
			}
			else {
				ans.insert(x);
				ans.insert(1 << 4);
				ans.insert(2 << 4);
				ans.insert(3 << 4);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> x;
	f();
	g();
	std::cout << "YES\n";
	std::cout << (*ans.begin());
	ans.erase(ans.begin());
	for (auto &&x : ans)
		std::cout << ' ' << x;
	return 0;
}