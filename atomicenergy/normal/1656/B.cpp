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
		long long k;
		cin >> k;
		vector<long long> v(n);
		set<long long> s;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (s.count(x - k) || s.count(x + k)) {
				ok = true;
			}
			s.insert(x);
		}
		cout << (ok?"YES":"NO") << endl;
	}
}