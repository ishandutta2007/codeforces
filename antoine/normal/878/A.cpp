#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> bits(10, 2); // 0, 1: const | 2: input | 3: !input
	for (int i = 0; i < n; ++i) {
		char op;
		int mask;
		cin >> op >> mask;
		for (int j = 0; j < 10; ++j) {
			if (op == '|') {
				if (mask & (1 << j))
					bits[j] = 1;
			}
			else if (op == '&') {
				if (!(mask & (1 << j)))
					bits[j] = 0;
			}
			else {
				if (mask & (1 << j))
					bits[j] ^= 1;
			}
		}
	}
	cout << "3\n& ";
	int mask = 1023;
	for (int j = 0; j < 10; ++j)
		if (bits[j] == 0)
			mask ^= 1 << j;
	cout << mask << "\n| ";
	mask = 0;
	for (int j = 0; j < 10; ++j)
		if (bits[j] == 1)
			mask |= 1 << j;
	cout << mask << "\n^ ";
	mask = 0;
	for (int j = 0; j < 10; ++j)
		if (bits[j] == 3)
			mask |= (1 << j);
	cout << mask;
	return 0;
}