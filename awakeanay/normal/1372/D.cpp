#include <iostream>

#define int long long

signed main() {
	int n;
	std::cin >> n;

	int ans = 0;
	int a[n+2];
	int pre[2][n+2];
	int suf[2][n+2];

	for(int i = 1; i <= n; i++)
		std::cin >> a[i];

	pre[0][0] = pre[1][0] = suf[0][n+1] = suf[1][n+1] = 0;

	for(int i = 1; i <= n; i++) {
		pre[i%2][i] = a[i];
		if(i > 1) pre[i%2][i] += pre[i%2][i-2];
		pre[1-i%2][i] = pre[1-i%2][i-1];

		suf[i%2][n+1-i] = a[n+1-i];
		if(i > 1) suf[i%2][n-i+1] += suf[i%2][n-i+2+1];
		suf[1-i%2][n-i+1] = suf[1-i%2][n-i+1+1];
	}

	for(int i = 1; i <= n; i++)
		ans = std::max(ans, a[i] + std::max(pre[0][i-1] + suf[1][i+1], pre[1][i-1] + suf[0][i+1]));

	std::cout << ans << std::endl;

	return 0;
}