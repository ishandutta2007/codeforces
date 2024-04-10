#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	
	if(n <= 3)
	{
		std::cout << 1 << std::endl;
		return 0;
	}
	
	long long seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
		
	std::pair<long long, int> ord[n];
	for(int i = 0; i < n; i++)
	{
		ord[i].first = seq[i];
		ord[i].second = i;
	}
	
	std::sort(ord, ord + n);
	
	long long diff[n-1];
	long long sum = 0;
	
	for(int i = 0; i < n-1; i++)
	{
		diff[i] = ord[i+1].first - ord[i].first;
		sum += diff[i];
	}
	
	bool poss = true;
	for(int i = 0; i < n-2; i++)
	{
		poss &= (diff[i] == diff[0]);
	}
	
	if(poss)
	{
		std::cout << ord[n-1].second + 1<< std::endl;
		return 0;
	}
	
	poss = true;
	for(int i = 1; i < n-1; i++)
	{
		poss &= (diff[i] == diff[1]);
	}
	
	if(poss)
	{
		std::cout << ord[0].second + 1 << std::endl;
		return 0;
	}
	
	long long major = sum/(n-2);
	poss = true;
	int j = -1;
	for(int i = 0; i < n-1; i++)
	{
		if(diff[i] != major)
		{
			if(i == n-1 || j != -1)
				poss = false;
			else if(diff[i] + diff[i+1] == major)
			{
				j = ord[i+1].second;
				i++;
			}
			else
				poss = false;
			
		}
	}
	
	
	if(poss)
		std::cout << j + 1;
	else
		std::cout << -1;
	std::cout << std::endl;
	
	return 0;
}