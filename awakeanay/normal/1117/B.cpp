#include <iostream>

int main()
{
	int n;
	long long m, k;
	std::cin >> n >> m >> k;
	
	long long max = 0, smax = 0;
	for(int i = 0; i < n; i++)
	{
		long long a;
		std::cin >> a;
		if(a > max)
		{
			smax = max;
			max = a;
		}
		else if(a > smax)
			smax = a;
	}
	long long answer = (max*k + smax)*(m/(k+1)) + max*(m % (k+1));
	std::cout << answer;
}