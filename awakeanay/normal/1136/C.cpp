#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, m;
	std::cin >> n >> m;

	int k = n + m - 1;
	std::vector<long long> a[k], b[k];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			long long val;
			std::cin >> val;
			a[i+j].push_back(val);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			long long val;
			std::cin >> val;
			b[i+j].push_back(val);
		}
	}

	for(int i = 0; i < k; i++)
	{
		std::sort(a[i].begin(), a[i].end());
		std::sort(b[i].begin(), b[i].end());
	}

	bool poss = true;
	for(int i = 0; i < k; i++)
	{
		if(a[i] != b[i])
			poss = false;
	}

	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";
}