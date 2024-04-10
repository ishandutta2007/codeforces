#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set <string> s;
int main() {
	int n, s1 = 0, s2 = 0;
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		int x, y;
		cin >> x >> y;
		s1 += x, s2 += y;
	}
	cout << min(s1, n - s1) + min(s2, n - s2);
}