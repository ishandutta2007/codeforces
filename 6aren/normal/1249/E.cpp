#include<bits/stdc++.h>
using namespace std;

int f[2][200005], a[200005], b[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		cin >> b[i];
	}
	f[1][1] = c;
	for (int i = 2; i <= n; i++) {
		f[0][i] = min(f[0][i - 1], f[1][i - 1]) + a[i];
		f[1][i] = min(f[0][i - 1] + c + b[i], f[1][i - 1] + b[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << min(f[0][i], f[1][i]) << ' ';
	}
	return 0;
}