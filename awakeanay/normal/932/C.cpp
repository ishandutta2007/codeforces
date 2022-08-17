#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	long N, A, B;
	std::cin >> N >> A >> B;
	
	for(long i = 0; i <= N/A; i++)
	{
		if((N-i*A) % B == 0)
		{
			int n = 1;
			for(long j = 0; j < i; j++)
			{
				for(int k = 1; k < A; k++)
					std::cout << n+k << " ";
				std::cout << n << " ";
				n += A;
			}
			
			for(long j = 0; j < (N-(i*A))/B; j++)
			{
				for(int k = 1; k < B; k++)
					std::cout << n+k << " ";
				std::cout << n << " ";
				n += B;
			}
			
			return 0;
		}
	}
	
	std::cout << -1;
	return 0;
}