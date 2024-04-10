#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
long long n, a[N], ans = 1e18;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		long long cur = 0, tot = 0;
		for(int j = i + 1; j <= n; j++) {
			long long nd = cur / a[j] + 1;
			cur = nd * a[j], tot += nd;
		}
		cur = 0;
		for(int j = i - 1; j; j--) {
			long long nd = cur / a[j] + 1;
			cur = nd * a[j], tot += nd;
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
	return 0;
}