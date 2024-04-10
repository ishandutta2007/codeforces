#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define int long long
#define INF 1000000000000000

signed main() {
	std::ios::sync_with_stdio(false);
	
	int n, k;
	std::cin >> n >> k;
	
	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::map<int, int> c1;
	std::map<int, int> c2;
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(abs(a[i])%(k*k) == 0) {
			ans += c2[a[i]/(k)];
		}
		
		if(abs(a[i])%k == 0) {
			c2[a[i]] += c1[a[i]/k];
		}
		
		c1[a[i]]++;
	}
	
	std::cout << ans << std::endl;
	return 0;
}