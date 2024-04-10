#include<bits/stdc++.h>

using namespace std;

int n, a[200005], mn = 0, u, check[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	a[1] = 0;
	for (int i = 1; i < n; i++) {
		cin >> u;
		a[i + 1] = a[i] + u;
		mn = min(mn, a[i + 1]);
	}
	int tmp = 1 - mn;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i] + tmp;
		if (a[i] > n) return cout << -1, 0;
		if (check[a[i]]) return cout << -1, 0;
		check[a[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}