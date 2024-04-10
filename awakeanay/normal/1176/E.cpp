#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define MAX 300005

signed main() {
	int t;
	std::cin >> t;
	
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		
		std::vector<int> Adj[n];
		
		for(int i = 0; i < m; i++) {
			int u, v;
			std::cin >> u >> v;
			u--; v--;
			Adj[u].push_back(v);
			Adj[v].push_back(u);
		}
		
		std::vector<int> mark(n, false);
		for(int i = 0; i < n; i++) {
			int cur = 0;
			for(int j : Adj[i]) {
				cur += mark[j];
			}
			if(cur == 0)
				mark[i] = true;
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += mark[i];
		
		if(ans > n-ans) {
			std::cout << n-ans << std::endl;
			for(int i = 0; i < n; i++)
				if(!mark[i])
					std::cout << i+1 << " ";
		}
		else {
			std::cout << ans << std::endl;
			for(int i = 0; i < n; i++)
				if(mark[i])
					std::cout << i+1 << " ";
		}
		std::cout << std::endl;
	}
}