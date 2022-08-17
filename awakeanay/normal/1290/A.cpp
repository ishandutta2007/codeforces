/*
Author: AwakeAnay
Date: 03/02/2020
Time: 19:59:07
*/

#include <iostream>

#define int long long
#define INF 10000000000

signed main() {
	int t;
	std::cin >> t;
	
	while(t--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		m--;
		
		int a[n];
		for(int i = 0; i < n; i++)
			std::cin >> a[i];
		
		k = std::min(k, m);
		
		int ans = 0;
		
		for(int i = 0; i <= k; i++) {
			int cur = INF;
			int l = m-k;
			for(int j = 0; j <= l; j++) {
				int now = std::max(a[i+j], a[n-1-(k-i)-(l-j)]);
				cur = std::min(cur, now);
			}
			ans = std::max(ans, cur);
		}
		
		std::cout << ans << std::endl;
	}
	
	return 0;
}