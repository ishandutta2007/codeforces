#include <iostream>
#include <cmath>

bool isSquare(long long c)
{
	long long r = sqrt(c);
	return (r*r == c);	
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	std::string N;
	std::cin >> N;
	
	int D = N.length();
	
	int answer = 10;
	
	int C = 1 << D;
	for(int i = 1; i < C; i++)
	{
		long long cur = 0; int d = 0;
		for(int j = 0; j < D; j++)
		{
			if((1 << j) & i)
			{
				if(d == 0 && N[j] == '0')
					break;
				
				cur *= 10;
				cur += (N[j]-'0');
				d++;
			}
		}
		
		if(cur > 0 && isSquare(cur))
			answer = std::min(answer, D-d);
		
	}
	
	if(answer == 10)
		std::cout << -1;
	else
		std::cout << answer;
	
	return 0;
}