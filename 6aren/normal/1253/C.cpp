#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define int long long

int a[200005], f[200005];

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = a[0];
	f[0] = a[0];
	cout << f[0] << ' ';
	for (int i = 1; i < n; i++) {
		sum += a[i];
		if (i >= m) {
			f[i] = sum + f[i - m];
		} else {
			f[i] = f[i - 1] + a[i];
		}
		cout << f[i] << ' ';
	}
	return 0;
}