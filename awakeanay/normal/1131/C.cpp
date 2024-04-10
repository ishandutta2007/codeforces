#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	
	long long a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::sort(a, a+n);
	
	for(int i = 0; i < n; i++)
		if(i%2 == 0)
			std::cout << a[i] << " ";
	
	for(int i = n-1; i >= 0; i--)
		if(i%2)
			std::cout << a[i] << " ";
	
	return 0;
}