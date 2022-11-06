#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <stack>

int n, x, y;

void trim(std::vector<int> &elts) {
	std::stack<int> temp;
	while (!elts.empty()) {
		if (elts.back() < n)
			temp.push(elts.back() + 1);
		elts.pop_back();
	}
	while (!temp.empty()) {
		elts.push_back(temp.top());
		temp.pop();
	}
}

bool query(std::vector<int> elts) {
	trim(elts);
	if (elts.size() == 0)
		return false;
	std::cout << "? " << elts.size();
	for (int i = 0; i < elts.size(); ++i)
		std::cout << ' ' << elts[i];
	std::cout << '\n';
	fflush(stdout);
	int ans;
	std::cin >> ans;
	if (ans == -1)
		return elts[1024 * 3];
	//exit(0);
	if (elts.size() & 1)
		return ans == y;
	return ans != 0;
}

int find1(std::vector<int> elts) {
	if (elts.size() <= 1)
		return elts.back();
	std::vector<int> sub[2];
	for (int i = 0; i < elts.size(); ++i)
		sub[i / (elts.size() / 2)].push_back(elts[i]);
	if (query(sub[0]))
		return find1(sub[0]);
	return find1(sub[1]);
}

int main() {
	std::cin >> n >> x >> y;
	int split = 2;
	int part = 512;
	std::vector<int> elts;
	for (;;) {
		for (int i = 0; i < 1024; i += (2 * part)) {
			for (int j = 0; j < part; ++j)
				elts.push_back(i + j);
		}
		if (part <= 1 || query(elts))
			break;
		elts.clear();
		split <<= 1;
		part >>= 1;
	}
	int a = find1(elts);
	elts.clear();
	int offset = (a / (2 * part)) * (2 * part) + part;
	for (int i = 0; i < part; ++i)
		elts.push_back(offset + i);
	int b = find1(elts);
	if (a > b)
		std::swap(a, b);
	std::cout << "! " << (a + 1) << ' ' << (b + 1) << '\n';
	fflush(stdout);
	return 0;
}