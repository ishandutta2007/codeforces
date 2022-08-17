#include <iostream>

#define MOD 1000000007

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	
	int a = std::max(n, m);
	int b = 2*k + 1;
	long long C[a][b];
	
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < std::min(b, i+1); j++)
		{
			if(j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = (C[i-1][j] + C[i-1][j-1] + MOD)%MOD;
		}
	}
	
	long long answer;
	if(n-1 < 2*k || m-1 < 2*k)
		answer = 0;
	else
		answer = (C[n-1][2*k]*C[m-1][2*k] + MOD)%MOD;
	
	std::cout << answer;
	
	return 0;
}