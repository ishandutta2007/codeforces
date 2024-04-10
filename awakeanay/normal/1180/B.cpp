#include <iostream>

#define INF 100000001

int main()
{
	int n;
	std::cin >> n;

	int seq[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
		if(seq[i] >= 0)
			seq[i] = - seq[i] - 1;
	}
	
	int id = 0;
	
	if(n % 2)
	{
		for(int i = 0; i < n; i++)
		{
			if(abs(seq[i]) > abs(seq[id]))
			{
				id = i;
			}
		}
		
		seq[id] = - seq[id] - 1;
	}
	
	for(int i = 0; i < n; i++)
		std::cout << seq[i] << " ";
	
	std::cout << std::endl;
	
	return 0;
}