#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

set <pair <int, int> > s;

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
//	cout << 15 * n << endl;
	for (int i = 1; i <= 2 * n + 3; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i % 2 || j == 3 || (i % 4 == 2 && j == 1) || (i % 4 == 0 && j == 5)) {
				s.insert({i, j});
			}
		}
	}
	s.erase({1, 4});
	s.erase({1, 5});
	if (n % 2) {
		s.erase({2 * n + 3, 1});
		s.erase({2 * n + 3, 2});
	}
	else {
		s.erase({2 * n + 3, 4});
		s.erase({2 * n + 3, 5});
	}
	cout << s.size() << endl;
	for (auto p : s) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}