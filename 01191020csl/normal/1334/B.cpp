#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		long long sum = 0;
		for (int i = n; i >= 1; i--) {
			sum += a[i];
			if (sum < 1ll * x * (n-i+1)) {
				cout << n-i << endl;
				break;
			}
		}
		if (sum >= 1ll * x * n) cout << n << endl;
	}
}