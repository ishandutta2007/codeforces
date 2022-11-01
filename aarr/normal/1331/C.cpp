#include <bits/stdc++.h>
using namespace std;
 
int get(int x, int y) {
	return (x >> y) & 1;
}
 
int main() {
	int n, ans = 0;
	cin >> n;
	if (get(n, 1)) {
		ans += 1 << 1;
	}
	if (get(n, 5)) {
		ans += 1 << 5;
	}
	if (get(n, 3)) {
		ans += 1 << 2;
	}
	if (get(n, 2)) {
		ans += 1 << 3;
	}
	if (get(n, 0)) {
		ans += 1 << 4;
	}
	if (get(n, 4)) {
		ans += 1 << 0;
	}
	cout << ans;
	return 0;
}