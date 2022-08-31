#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 3000

int c[MAXN];
std::vector<int> Adj[MAXN];
bool poss;

std::vector<int> dfs(int u) {
	std::vector<int> ret;
	for(int v : Adj[u]) {
		std::vector<int> vv = dfs(v);
		ret.insert(ret.end(), vv.begin(), vv.end());
	}

	if(c[u] > ret.size()) {
		poss = false;
		return ret;
	}

	ret.insert(ret.begin()+c[u], u);
	return ret;
}

int main() {
	poss = true;
	
	int n;
	std::cin >> n;

	int root;
	for(int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;
		if(x == 0)
			root = i;
		else
			Adj[x].push_back(i);
		c[i] = y;
	}

	std::vector<int> ans = dfs(root);	

	if(poss)
		std::cout << "YES" << std::endl;
	else {
		std::cout << "NO" << std::endl;
		return 0;
	}

	int rev[n+1];
	for(int i = 0; i < n; i++) {
		rev[ans[i]] = i+1;
	}
	
	for(int i = 0; i < n; i++)
		std::cout << rev[i+1] << " ";
	std::cout << std::endl;

	return 0;
}