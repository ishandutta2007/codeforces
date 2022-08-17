#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;
	
	int prob[n];
	for(int i = 0; i < n; i++)
		prob[i] = 0;
	
	int tProbs = 0;
	for(int i = 0; i < m; i++)
	{
		int p;
		std::cin >> p; p--;
		if(prob[p] == 0)
			tProbs++;
		prob[p]++;
		if(tProbs == n)
		{
			tProbs = 0;
			std::cout << 1;
			for(int i = 0; i < n; i++)
			{
				prob[i]--;
				if(prob[i] > 0)
					tProbs++;
			}
		}
		else
		std::cout << 0;
	}
	
	return 0;
}