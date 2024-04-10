#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
	int n;
	std::cin >> n;

	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	std::vector<std::pair<int, int> > help(n);
	for(int i = 0; i < n; i++) {
		help[i].first = a[i];
		help[i].second = i+1;
	}

	std::sort(help.begin(), help.end());
	std::reverse(help.begin(), help.end());

	std::vector<std::pair<int, int> > edges;
	std::vector<std::vector<int> > par(std::vector<std::vector<int> >(20, std::vector<int>(2*n+1, -1)));

	for(int i = 1; i < n; i++) {
		edges.push_back({2*help[i-1].second, 2*help[i].second});
		par[0][2*help[i].second] = 2*help[i-1].second;
		for(int j = 1; j < 20; j++) {
			if(par[j-1][2*help[i].second] == -1)
				break;

			par[j][2*help[i].second] = par[j-1][par[j-1][2*help[i].second]];
		}
	}

	int last = 2*help[n-1].second;
	int dist = n;
	for(int i = 0; i < n; i++) {
		if(help[i].first == 1) {
			edges.push_back({2*help[i].second, 2*help[i].second-1});
			continue;
		}

		int change = dist-help[i].first;
		for(int i = 19; i >= 0; i--) {
			if((1 << i) <= change) {
				last = par[i][last];
				change -= (1 << i);
			}
		}

		if(i+help[i].first-1 < n)
			last = 2*help[i+help[i].first-1].second;
		
		edges.push_back({2*help[i].second-1, last});

		par[0][2*help[i].second-1] = last;
		for(int j = 1; j < 20; j++) {
			if(par[j-1][2*help[i].second-1] == -1)
				break;

			par[j][2*help[i].second-1] = par[j-1][par[j-1][2*help[i].second-1]];
		}

		last = 2*help[i].second-1;
		dist = help[i].first;
	}

	for(auto j : edges)
		std::cout << j.first << " " << j.second << std::endl;

	return 0;
}