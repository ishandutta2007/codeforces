#include<bits/stdc++.h>

using namespace std;

int n, a[20];

bool check(int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 1; i >>= 1) {
		for (int j = 1; j <= n; j += i) {
			if (check(j, j + i - 1)) return cout << i, 0;
		}
	}
	cout << ans;
	return 0;
}