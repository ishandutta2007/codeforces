#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10000000

int main() 
{
	long long n;
	std::cin >> n;
	
	std::vector<long long> fun;
	
	int i;
	for(i = 1; i*i < n; i++)
	{
		if(n % i == 0)
		{
			fun.push_back(n/i + n*(n/i - 1)/2);
			fun.push_back(i + n*(i-1)/2);
		}
	}
	
	if(i*i == n)
		fun.push_back(i + n*(i-1)/2);
	
	std::sort(fun.begin(), fun.end());
	
	for(i = 0; i < fun.size(); i++)
		std::cout << fun[i] << " ";
	
	return 0;
}