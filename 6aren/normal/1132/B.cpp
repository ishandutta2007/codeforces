#include <bits/stdc++.h>

using namespace std;

int n, a[300005], m;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u;
		cin >> u;
		cout << sum - a[n - u] << endl;
	}
	return 0;
}