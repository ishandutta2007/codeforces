#include <iostream>

long long coins[9];

bool check(int i, long long val)
{
	//std::cout << i << " " << val << std::endl;
	
	if(val < 0)
		return false;
	
	if(coins[i]*i >= val && val % i == 0)
		return true;
	
	if(i == 1)
		return false;
	
	long long max;
	if(coins[i]*i < val)
		max = coins[i];
	else
		max = val/i;
	
	bool next[8];
	for(int j = 0; j < 8; j++)
		next[j] = false;
	
	for(int j = 0; j < 8 && (max >= j); j++)
	{
		int m = (i*(max-j)) % 8;
		if(next[m] && j > 1)
		{
			//std::cout << i << " " << val << " " << m << std::endl;
			continue;
		}
		next[m] = true;
		
		if(check(i-1, val - i*(max - j)))
			return true;
	}
	
	return false;
}

int main()
{
	long long w;
	std::cin >> w;
	
	long long max = 0;
	for(int i = 1; i <= 8; i++)
	{
		std::cin >> coins[i];
		max += i*coins[i];
	}
	
	if(max <= w)
		std::cout << max;
	else
	{
		while(!check(8, w))
			w--;
		std::cout << w;
	}
	
	return 0;
}