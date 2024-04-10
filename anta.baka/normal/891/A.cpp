#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[n];
	int c = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		c += (a[i] == 1);
	}
	if(c) return cout << n - c, 0;
	int lo = INT_MAX;
	for(int i = 0; i < n; i++) {
		int g = a[i];
		for(int j = i + 1; j < n; j++) {
			g = __gcd(g, a[j]);
			if(g == 1) {
				lo = min(lo, j - i);
				break;
			}
		}
	}
	if(lo == INT_MAX) return cout << -1, 0;
	cout << n - 1 + lo;
}