#include <bits/stdc++.h>

int a, b;
bool vis[100005];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> a >> b;
	std::vector<int> pa;
	int sa = 0;
	for (int i = 1; sa + i <= a; ++i) {
		pa.push_back(i);
		sa += i;
	}
	for (int i = (int)pa.size() - (a - sa); i < (int)pa.size(); ++i) {
		++pa[i];
		++sa;
	}
	for (int v : pa) {
		vis[v] = 1;
	}
	std::vector<int> pb;
	int sb = 0;
	for (int i = 1; sb + i <= b; ++i) {
		if (!vis[i]) {
			pb.push_back(i);
			sb += i;
		}
	}

	std::cout << pa.size() << "\n";
	for (int v : pa) {
		std::cout << v << " ";
	}
	std::cout << "\n";
	std::cout << pb.size() << "\n";
	for (int v : pb) {
		std::cout << v << " ";
	}
	std::cout << "\n";
}