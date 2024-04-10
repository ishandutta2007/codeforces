#include<bits/stdc++.h>
using namespace std;
inline long long query1(int x) {
	long long ans = 0, b = 1;
	while (x > 9) x -= 9, ans += b * 9, b *= 10;
	return ans + b * x;
}
inline long long query2(int x) {
	if (x <= 8) return x;
	long long ans = 8, b = 10;
	x -= 8;
	while (x > 9) x -= 9, ans += b * 9, b *= 10;
	return ans + b * x;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0; i <= 9; i++)
			if (i + k <= 9) {
				int d = (i+i+k)*(k+1)/2;
				if (d <= n && (n-d) % (k+1) == 0) ans = min(ans, query1((n-d)/(k+1))*10+i);
			}
			else {
				int d1 = (10-i), d2 = (k+1-d1), d = (i+9)*d1/2+(d2-1)*d2/2+d2;
				long long b = 10, add = i;
				while (d <= n) {
					if ((n-d)%(k+1) == 0) ans = min(ans, query2((n-d)/(k+1))*b+add);
					d += d1 * 9;
					add += b * 9, b *= 10;
				}
			}
		if (ans < 0x3f3f3f3f3f3f3f3f) cout << ans << endl;
		else cout << -1 << endl;
	}
}