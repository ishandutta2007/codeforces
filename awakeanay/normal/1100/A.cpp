#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;
	
	int seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
	
	int maxA = 0;
	for(int a = 0; a < n; a++)
	{
		int diff = 0;
		for(int i = 0; i < n; i++)
		{
			if(!(i%k == a%k))
				diff += seq[i];
		}
		maxA = std::max(maxA, abs(diff));
	}
	
	std::cout << maxA;
	
	return 0;
}