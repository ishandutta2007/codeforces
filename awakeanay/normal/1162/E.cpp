#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int a[n];
	int min = 100;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		min = std::min(min, a[i]);
	}

	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == min)
			count++;
	}

	if(count >= n/2 + 1)
		std::cout << "Bob";
	else
		std::cout << "Alice";
}