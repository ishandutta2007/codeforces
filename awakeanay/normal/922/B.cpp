#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	long long answer = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			int m = (i^j^0);
			if(m < j && m + j > i)
				answer++;
		}
	}
	
	std::cout << answer;
	
	return 0;
}