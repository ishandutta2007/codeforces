#include<bits/stdc++.h>
using namespace std;
void solve(int l, int r, long long k) {
	if (l > r) cout << endl;
	for (int i = l; i <= r; i++)
		if (r-i > 60 || (1ll<<max(r-i-1, 0)) >= k) {
			for (int j = i; j >= l; j--) cout << j << ' ';
			solve(i + 1, r, k);
			return;
		}
		else k -= 1ll<<r-i-1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		if (n <= 60 && (1ll<<n-1) < k) {
			puts("-1");
			continue;
		}
		solve(1, n, k);
	}
}