#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	long long seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];

	std::sort(seq, seq + n);

	if(seq[n-3] + seq[n-2] > seq[n-1])
	{
		std::cout << "YES" << std::endl;
		for(int i = 0; i < n; i++)
			if(i%2 == 1)
				std::cout << seq[i] << " ";

		for(int i = n-1; i >= 0; i--)
			if(i%2 == 0)
				std::cout << seq[i] << " ";
	}
	else
		std::cout << "NO";

	std::cout << std::endl;

	return 0;
}