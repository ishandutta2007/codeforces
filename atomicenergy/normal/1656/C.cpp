#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		bool adj = false;
		set<long long> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (s.count(x - 1) || s.count(x + 1)) adj = true;
			s.insert(x);
		}
		if (!s.count(1) || !adj) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}