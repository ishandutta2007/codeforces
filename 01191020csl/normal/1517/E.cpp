#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[200001];
long long S[200001];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		S[0] = 0, S[1] = a[1];
		for (int i = 2; i <= n; i++) S[i] = S[i-2] + a[i];
		long long tot = 0;
		for (int i = 1; i <= n; i++) tot += a[i];
		long long val = 0;
		long long ans = 1;
		for (int i = 1; i < n; i++) {
			val += a[i];
			if (val * 2 >= tot) break;
			int l = -1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (i + mid*2 < n && 2*(val+S[i+mid*2]-S[i]) < tot) l = mid;
				else r = mid - 1;
			}
			ans += l+1;
			l = -1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (i + mid*2 <= n-2 && 2*(val+a[n]+S[i+mid*2]-S[i]) < tot) l = mid;
				else r = mid - 1;
			}
			ans += l+1;
		}
		val = 0;
		for (int i = 2; i < n; i++) {
			val += a[i];
			if (val * 2 >= tot) break;
			int l = -1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (i + mid*2 < n && 2*(val+S[i+mid*2]-S[i]) < tot) l = mid;
				else r = mid - 1;
			}
			ans += l+1;
			l = -1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (i + mid*2 <= n-2 && 2*(val+a[n]+S[i+mid*2]-S[i]) < tot) l = mid;
				else r = mid - 1;
			}
			ans += l+1;
		}
		val = 0;
		for (int i = n; i >= 1; i--) {
			val += a[i];
			if (val * 2 >= tot) break;
			++ans;
		}
		cout << ans % mod << endl;
	}
}