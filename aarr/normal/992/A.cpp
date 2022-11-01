#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set <int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != 0) {
			s.insert(x);
		}
	}
	cout << s.size();
	return 0;
}