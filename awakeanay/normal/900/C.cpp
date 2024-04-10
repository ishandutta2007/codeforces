#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	int p[N+1];
	p[0] = 0;
	for(int i = 1; i <= N; i++)
	{
		std::cin >> p[i];
	}
	
	int blockage[N+1];
	int record[N+1];
	record[0] = 0;
	blockage[0] = -1;
	for(int i = 1; i <= N; i++)
	{
		blockage[i] = 0;
		record[i] = 0;
	}
	
	int best = 0; int sbest = 0; int max_b = 1;
	
	for(int i = 1; i <= N; i++)
	{
		if(p[i] > p[best])
		{
			sbest = best;
			best = i;
			record[i]++;
		}
		else if(p[i] > p[sbest])
		{
			sbest = i;
			blockage[best]++;
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(blockage[i] - record[i] > blockage[max_b] - record[max_b])
		{
			max_b = i;
		}
		else if(blockage[i] - record[i] == blockage[max_b] - record[max_b] && p[i] < p[max_b])
		{
			max_b = i;
		}
	}
	
	std::cout << p[max_b];
	
	return 0;
}