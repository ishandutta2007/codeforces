#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;

	int p[n];
	for(int i = 0; i < n; i++)
		std::cin >> p[i];

	std::vector<int> near[n+1];
	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		near[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
		std::sort(near[i].begin(), near[i].end());

	int rank = 1;
	std::vector<int> here = near[p[n-1]];

	for(int i = n-2; i >= 0; i--)
	{
		if(!std::binary_search(here.begin(), here.end(), p[i]))
		{
			rank++;
			auto it = std::set_intersection(here.begin(), here.end(), near[p[i]].begin(), near[p[i]].end(), here.begin());
            here.resize(it - here.begin());
		}
	}

	std::cout << n-rank;

	return 0;
}