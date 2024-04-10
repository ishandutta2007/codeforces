#include <iostream>

int main()
{
	long long n;
	std::cin >> n;
	
	long long answer = 0;
	for(int i = 2; i < n; i++)
		answer += i*(i+1);
	
	std::cout << answer;
	
	return 0;
}