#include <iostream>

int main()
{
	long long int N;
	std::cin >> N;
	
	int m = N%10;
	if(m > 5)
		N += 10-m;
	else
		N -= m;
	std::cout << N;
	return 0;
}