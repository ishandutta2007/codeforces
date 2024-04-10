#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, x, y;
		cin >> n >> x >> y;
		if(x > y) {
			swap(x, y);
		}
		
		long long a = x + y - n + 1;
		a = max(a, 1ll);
		a = min(a, n);
		long long b = min(n, x + y - 1);
		cout << a << " " << b << endl;
	}
	return 0;
}