#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	long long x[N], y;
	for(int i = 0; i < N; i++)
	{
		std::cin >> x[i] >> y;
	}
	
	long long left, right;
	left = 0; right = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(x[i] > 0)
			right++;
		else
			left++;
	}
	
	if(left <= 1 || right <= 1)
		std::cout << "Yes";
	else
		std::cout << "No";
	
	std::cout << std::endl;
	
	return 0;
}