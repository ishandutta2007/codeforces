#include <iostream>
#include <vector>
#include <stack>
#include <map>

#define int long long
#define MAX 2000000



signed main() {
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	int sz = 0;
	std::map<int, std::vector<int> > query;
	std::vector<std::string> list(n);
	for(int i = 0; i < n; i++) {
		std::cin >> list[i];
		int k;
		std::cin >> k;
		for(int j = 0; j < k; j++) {
			int x;
			std::cin >> x;
			query[x-1].push_back(i);
			sz = std::max(sz, x-1+list[i].size());
		}
	}
	
	std::string s(sz, 'a');
	std::stack<std::pair<int, int> > st;
	for(int i = 0; i < MAX; i++) {
		for(int j : query[i]) {
			st.push({i, j});
		}
		
		while(!st.empty() && i >= list[st.top().second].size() + st.top().first)
			st.pop();
		
		if(!st.empty()) {
			//std::cout << st.top().second << " " << i-st.top().first << std::endl;
			s[i] = list[st.top().second][i-st.top().first];
		}
	}
	
	std::cout << s << std::endl;
}