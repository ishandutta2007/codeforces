#include <iostream>

int main()
{
	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;
	
	long long answer = 0;
	
	answer += 4 + (a + c);
	answer += 2*(b + d);
	answer += abs(a-c);
	
	std::cout << answer;
	
	return 0;
}