#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int> cur;
	for (int i = 0; i < m; ++i) {
		cur.clear();
		int t, r;
		cin >> t;
		bool goour = false;
		for (int j = 0; j < t; ++j) {
			cin >> r;
			if (cur.find(-r) != cur.end())
				goour = true;
			cur.insert(r);
		}
		if (!goour) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}