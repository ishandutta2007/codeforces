#include <iostream>

#define INF 2000000000

int main()
{
	int n;
	std::cin >> n;
	
	long long seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
	
	long long last = INF;
	long long answer = 0;
	for(int i = n-1; i >= 0; i--)
	{
		answer += std::min(last - 1, seq[i]);
		last = std::min(last - 1, seq[i]);
		if(last == 1)
			break;
		//std::cout << std::min(last - 1, seq[i]) << std::endl;
	}
	
	std::cout << answer;
	
	return 0;
}