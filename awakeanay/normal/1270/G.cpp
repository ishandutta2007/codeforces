#include <iostream>
#include <vector>
#include <stack>

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	// std::cout.tie(0);
	
	int t;
	std::cin >> t;
	
	while(t--) {
		int n;
		scanf("%d", &n);
		
		int a[n+1];
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			a[i] = i-x;
		}
		
		std::vector<int> vis(n+1, 0);
		std::stack<int> dfs;
		
		int i = 1;
		while(!vis[i]) {
			vis[i] = true;
			dfs.push(i);
			i = a[i];
		}
		
		std::vector<int> ans;
		while(dfs.top() != i) {
			ans.push_back(dfs.top());
			dfs.pop();
		}
		ans.push_back(i);
		
		printf("%d\n", ans.size());
		for(int j : ans)
			printf("%d ", j);
		printf("\n");
	}
	
	return 0;
}