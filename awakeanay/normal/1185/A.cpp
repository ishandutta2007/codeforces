#include <iostream>
#include <algorithm>

int main()
{
	long long a, b, c, d;
	long long seq[3];
	std::cin >> seq[0] >> seq[1] >> seq[2] >> d;
	
	std::sort(seq, seq + 3);
	a = seq[0];
	b = seq[1];
	c = seq[2];
	
	long long answer = 0;
	answer += a - std::min(b-d,a);
	answer += std::max(b+d,c) - c;
	
	std::cout << answer;
	
	return 0;
}