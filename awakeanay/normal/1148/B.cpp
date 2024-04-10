#include <iostream>

#define int long long
#define INF 1000000000000

signed main() {
	int n, m, ta, tb, k;
	std::cin >> n >> m >> ta >> tb >> k;
	
	int a[n+1], b[m];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	a[n] = INF;
	for(int i = 0; i < m; i++)
		std::cin >> b[i];
	
	if(m <= k || n <= k) {
		std::cout << -1;
		return 0;
	}
	
	int l = 0;
	int ans = 0;
	for(int i = 0; i <= std::min(k, n); i++) {
		while(l < m && b[l] < a[i]+ta)
			l++;
		if(l+k-i >= m) {
			std::cout << -1;
			return 0;
		}
		ans = std::max(ans, b[l+k-i]);
	}
	
	std::cout << ans+tb << std::endl;
	
	return 0;
}