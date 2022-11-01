#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, r; cin >> n >> r;
	int x[n];
	for(int i = 0; i < n; i++) cin >> x[i];
	vector<ld> y(n, r);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++)
			if(int(abs(x[i] - x[j])) <= 2 * r)
				y[i] = max(y[i], y[j] + sqrt(ld(4 * r * r - (x[i] - x[j]) * (x[i] - x[j]))));
	}
	cout.precision(10);
	for(int i = 0; i < n; i++) cout << fixed << y[i] << ' ';
}