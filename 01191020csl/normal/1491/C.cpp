#include<bits/stdc++.h>
using namespace std;
int a[5001], s[5001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i], s[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 2; i + j <= n && j <= a[i]; j++)
				++s[i+j];
			a[i] -= s[i];
			if (a[i] <= 1) {
				if (i < n) s[i+1] += 1-a[i];
				a[i] = 1;
			}
			ans += a[i] - 1;
		}
		cout << ans << endl;
	}
}