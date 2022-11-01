#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

int a[N];

long long po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		if (p == 1) {
			if (n % 2) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			cout << '\n';
			continue;
		}
		long long s1 = 0, s2 = 0;
		long long x = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1 && x != 0 && x <= n) {
				for (int j = a[i]; j < a[i + 1]; j++) {
					x *= p;
					if (x > n) {
						break;
					}
				}
			}
			
			if (x <= 0) {
				s1 += po(p, a[i]);
				s1 %= mod;
				x++;
			}
			else {
				s2 += po(p, a[i]);
				s2 %= mod;
				x--;
			}
		}
	//	if (x > 0) {
			cout << (s1 - s2 + mod) % mod << '\n';
	//	}
	//	else {
	//		cout << (s2 - s1 + mod) % mod << '\n';
	//	}
		
	}
	
	return 0;
}