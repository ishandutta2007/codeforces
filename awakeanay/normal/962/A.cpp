#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	
	int N;
	std::cin >> N;
	
	long A[N]; long sum = 0;
	for(int i = 0; i < N; i++)
	{
		std::cin >> A[i];
		sum += A[i];
	}
	
	sum = (sum/2) + (sum%2);
	
	long runner = 0;
	for(int i = 0; i < N; i++)
	{
		runner += A[i];
		if(runner >= sum)
		{
			std::cout << i+1;
			return 0;
		}
	}
}