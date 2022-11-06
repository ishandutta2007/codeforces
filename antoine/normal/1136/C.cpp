#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	array<map<int, multiset<int>>, 2> s;
	for (int r = 0; r < 2; ++r)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				s[r][i + j].insert(x);
			}

	cout << (s[0] == s[1] ? "YES" : "NO");
	return 0;
}