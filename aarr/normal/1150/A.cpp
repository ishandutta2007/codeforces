#include <iostream>
#include <map>
using namespace std;

map <string, string> mp;
int main() {
	int n, m, r, mn = 1005, mx = 0;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mn = min(mn, x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
	}
	cout << max(r / mn * mx + r % mn, r);
	return 0;
}