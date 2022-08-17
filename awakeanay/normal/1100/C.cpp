#include <cmath>
#include <iostream>
#include <iomanip>

#define PI 3.1415926535897

int main()
{
	long double n, R;
	std::cin >> n >> R;
	
	long double k = sin((n-2)*PI/(2*n));
	k /= sin(2*PI/n);
	std::cout << std::fixed << std::setprecision(10) << R/(2*k - 1);
	
	return 0;
}