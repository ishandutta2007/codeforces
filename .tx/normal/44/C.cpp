#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, n, i, x, y, g;
	cin >> n >> m;
	vector<int> a(n+1, 0);
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		for (g = x; g <= y; g++) {
			a[g]++;
		}
	}
	for (i = 1; i <= n; i++) {
		if (a[i] != 1) {
			cout << i << " " << a[i];
			return 0;
		}
	}
	cout << "OK";

	return 0;
}//akukpc