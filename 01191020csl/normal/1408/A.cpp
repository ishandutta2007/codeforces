#include<bits/stdc++.h>
using namespace std;
int a[101], b[101], c[101];
int ans[101];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		ans[1] = a[1];
		for (int i = 2; i < n; i++) {
			if (a[i] == ans[i-1]) ans[i] = b[i];
			else ans[i] = a[i];
		}
		if (a[n] == ans[n-1] || a[n] == ans[1]) {
			if (b[n] == ans[n-1] || b[n] == ans[1]) ans[n] = c[n];
			else ans[n] = b[n];
		}
		else ans[n] = a[n];
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
}