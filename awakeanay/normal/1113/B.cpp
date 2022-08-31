#include <iostream>
#include <set>

#define INF 100000000

int main()
{
	int n;
	std::cin >> n;
	
	int a[n];
	long long answer = 0;
	long long sum = 0;
	int min = 101;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		sum += a[i];
		min = std::min(a[i], min);
	}
	answer = sum;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 2; j*j <= a[i]; j++)
		{
			if(a[i]%j == 0)
			{
				answer = std::min(sum - a[i] + a[i]/j + min*(j-1), answer);
				int k = a[i]/j;
				answer = std::min(sum - a[i] + a[i]/k + min*(k-1), answer);
			}
		}
	}
	
	std::cout << answer;
	
	return 0;
}