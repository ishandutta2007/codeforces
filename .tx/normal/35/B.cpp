#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, k, i, g, c, x, y;
	string id;
	cin >> n >> m >> k;
	set<int> mn;
	for (i = 0; i < n; i++) {
		for (g = 0; g < m; g++) {
			mn.insert(i * m + g);
		}
	}
	map<string, int> mm;
	set<int>::iterator it;
	for (i = 0; i < k; i++) {
		cin >> c;
		if (c == 1) {
			cin >> x >> y >> id;
			x = (x - 1) * m + y - 1;
			if (mn.count(x)) {
				mm[id] = x;
				mn.erase(x);
			}
			else {
				it = mn.upper_bound(x);
				if (it != mn.end()) {
					mm[id] = *it;
					mn.erase(*it);
				}
			}
		}
		else {
			cin >> id;
			if (!mm.count(id)) {
				cout << "-1 -1\n";
				continue;
			}
			x = mm[id];
			if (x == -1) {
				cout << "-1 -1\n";
				continue;
			}
			mn.insert(x);
			mm[id] = -1;
			cout << x / m + 1 << ' ' << x % m + 1<< endl;
		}
	}
			


	
	return 0;
}//dbnsul