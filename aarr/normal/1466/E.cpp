#include <bits/stdc++.h>
using namespace std;

const int N = 500 * 1000 + 5, A = 61, mod = 1000 * 1000 * 1000 + 7;

long long a[N];
long long cnt[A];
long long f1[A], f2[N];

inline long long get(long long x, int y) {
	return (x >> y) & 1;
}

long long po2[A];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	po2[0] = 1;
	for (int i = 1; i < A; i++) {
		po2[i] = po2[i - 1] * 2;
		po2[i] %= mod;
	}
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < A; j++) {
				if (get(a[i], j)) {
					cnt[j]++;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < A; i++) {
			f1[i] = cnt[i] * cnt[i];
			f2[i] = 1ll * n * n;
			f1[i] %= mod;
			for (int j = 0; j < A; j++) {
				long long x = 1ll * f1[i] * po2[i];
				x %= mod;
				x *= po2[j];
				x %= mod;
				x *= n;
				x %= mod;
				ans += x;
			}
			ans %= mod;
		}
	//	cout << "73 " << ans << endl;
		for (int i = 0; i < n; i++) {
			long long x1 = 0, x2 = 0;
			for (int j = 0; j < A; j++) {
				if (get(a[i], j)) {
					x1 += po2[j] * cnt[j];
					x1 %= mod;
				}
				else {
					x2 += po2[j] * (n - cnt[j]);
					x2 %= mod;
				}
			}
			ans += 1ll * mod * mod - x1 * x2;
			ans %= mod;
		}
		cout << ans << '\n';
		
		
		
		
		for (int i = 0; i < A; i++) {
			cnt[i] = 0;
		}
	}
	
	return 0;
}