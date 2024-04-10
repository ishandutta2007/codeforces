#include<bits/stdc++.h>
using namespace std;

int a[150], n;

int check(int x, int y) {
	if (x % 2 == 0) return 1e9;
	if (y % 2 == 1) return 1e9;
	int res = 0;
	for (int i = 1; i < x; i += 2) {
		res += a[i + 1] - a[i];
	}
	for (int i = x + 1; i < y; i += 2) {
		res += a[i + 1] - a[i];
	}
	for (int i = y + 1; i <= 2 * n; i += 2) {
		res += a[i + 1] - a[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 2 * n + 1);
	int mn = 1e9;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = i + 1; j <= 2 * n; j++) {
			mn = min(mn, check(i, j));
		}
	}
	cout << mn;
	return 0;
}