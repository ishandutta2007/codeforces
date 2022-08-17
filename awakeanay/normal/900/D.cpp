#include <iostream>
#include <cmath>
#define mod 1000000007

long long int power(long long int x, unsigned long long int y, long long int p)
{
	long long int res = 1;
	x = x % p;
	
	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % p;
			
		y = y>>1;
		x = (x*x) % p;  
	}
	return res;
}

int main()
{
	long long x, y;
	std::cin >> x >> y;
	
	if(y%x != 0)
	{
		std::cout << 0;
		return 0;
	}
	else if(x == y)
	{
		std::cout << 1;
		return 0;
	}
	
	long long k = y/x;
	long long oNum = k;
	long long answer = 0;
	
	long long pf[25];
	for(int i = 0; i < 25; i++)
		pf[i] = -1;
	
	int i = 2; int j = 0;
	while(i*i <= k)
	{
		if(k%i == 0)
		{
			pf[j] = i;
			while(k%i == 0) k/=i;
			j++;
		}
		i++;
	}
	
	if(k != 1)
	{
		pf[j] = k;
		j++;	
	}
	
	for(int i = 0; i < power(2, j, mod); i++)
	{
		int a = 0; long long prod = 1;
		for(int b = 0; b < j; b++)
		{
			if(i & (1<<b))
			{
				prod = prod*pf[b];
				a++;
			}
		}
		//std::cout << prod  << " " << j << std::endl;
		answer = (answer + ((a%2 == 1)*(-2) + 1)*(power(2, oNum/prod - 1, mod)))%mod;
	}
	
	answer = (answer + mod)%mod;
	std::cout << answer << std::endl;
	
	return 0;
}