#include<bits/stdc++.h>
using namespace std;
int a[100001];
int ans[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		int p = 1, q = n, x = 0;
		while (p <= q) {
			ans[++x] = a[p++];
			if (p > q) break;
			ans[++x] = a[q--];
		}
		for (int i = n; i >= 1; i--) cout << ans[i] << ' ';
		cout << endl;
	}
}