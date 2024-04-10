#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	long long max = 0;
	long long last = -1;
	int answer = 0;
	
	long long seq[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
		max = std::max(seq[i], max);
	}
	
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(seq[i] != max)
			count = 0;
		else
		{
			count++;
			answer = std::max(count, answer);
		}
	}
	
	std::cout << answer;
	return 0;
}