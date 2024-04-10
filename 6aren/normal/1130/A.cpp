#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a[105];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int d = -1000; d <= 1000; d++) {
		if (!d) continue;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] * d > 0) cnt++;
		}
		if (cnt >= (n + 1) / 2) return cout << d, 0;
	}
	cout << 0;
	return 0;
}
//g++ online.cpp -o online.exe