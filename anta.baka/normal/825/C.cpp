#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000], ans;

int f(int x, int y) {
	assert(x != 0);
	int ret = 0;
	while(2 * x < y) {
		x *= 2;
		ret++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		ans += f(k, a[i]);
		k = max(k, a[i]);
	}
	cout << ans;
}