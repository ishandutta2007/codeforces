#include <bits/stdc++.h>

const int N = 1 << 16;

int n;
int a[N], lst[N];

void getAns(int x) {
	std::cout << "!";
	for (int i = 0; i < n; ++i) {
		std::cout << " " << (a[i] ^ x);
	}
	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		std::cout << "XOR " << 1 << " " << i + 1 << std::endl;
		std::cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		lst[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		if (~lst[a[i]]) {
			int x;
			std::cout << "OR " << lst[a[i]] + 1 << " " << i + 1 << std::endl;
			std::cin >> x;
			getAns(a[i] ^ x);
			return 0;
		}
		lst[a[i]] = i;
	}
	
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 2) {
			p = i;
			break;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			int x, y;
			std::cout << "OR " << 1 << " " << i + 1 << std::endl;
			std::cin >> x;
			std::cout << "OR " << 1 << " " << p + 1 << std::endl;
			std::cin >> y;
			getAns((x ^ 1) | (y & 1));
			return 0;
		}
	}
}