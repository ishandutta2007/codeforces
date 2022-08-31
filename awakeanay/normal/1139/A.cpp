#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	long answer = 0;
	for(int i = 0; i < n; i++)
	{
		char a;
		std::cin >> a;
		if((a - '0')%2 == 0)
			answer += i+1;
	}
	
	std::cout << answer;
	
	return 0;
}