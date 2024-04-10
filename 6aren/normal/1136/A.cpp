#include<bits/stdc++.h>

using namespace std;

int n, l[105], r[105], k;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		if (k <= r[i] && k >= l[i]) {
			return cout << n - i + 1, 0;
			break;
		}
	}
	cout << 0;
	return 0;
}