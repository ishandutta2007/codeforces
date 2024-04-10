#include <iostream>
#include <set>
using namespace std;

const int N = 55;

set<int> s[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			s[i].insert(x);
		}
	}
	bool b = true;
	for (int i = 1; i <= n; i++) {
		if (s[i].size() == n && b) {
			cout << n << " ";
			b = false;
		}
		else {
			cout << s[i].size() - 1 << " ";
		}
	}
	return 0;
}