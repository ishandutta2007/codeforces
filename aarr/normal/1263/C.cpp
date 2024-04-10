#include <iostream>
#include <set>
using namespace std;

set <int> s;
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		while (s.size()) {
			s.erase(s.begin());
		}
		for (int j = 1; 1ll * j * j <= n; j++) {
			s.insert(n / j);
			s.insert(j);
		}
		s.insert(0);
		cout << s.size() << endl;
		for (auto x : s) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}