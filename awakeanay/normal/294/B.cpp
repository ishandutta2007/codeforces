#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define int long long

#define MOD 998244353

int poss[26][2];

signed main() {
	int n;
	std::cin >> n;
	
	std::vector<int> book[2];
	for(int i = 0; i < n; i++) {
		int t, w;
		std::cin >> t >> w;
		t--;
		book[t].push_back(w);
	}
	
	book[0].push_back(0);
	book[1].push_back(0);
	
	for(int i = 0; i < 2; i++)
		std::sort(book[i].begin(), book[i].end());
	
	int ans = 2*n;
	for(int i = 0; i < book[0].size(); i++) {
		for(int j = 0; j < book[1].size(); j++) {
			int cur = 0;
			for(int k = book[1].size()-1-j; k >= 0; k--)
				cur += book[1][k];
			for(int k = book[0].size()-1-i; k >= 0; k--)
				cur += book[0][k];
			if(cur <= i+2*j)
				ans = std::min(ans, i+2*j);
		}
	}
	
	std::cout << ans << std::endl;
	
	return 0;
}