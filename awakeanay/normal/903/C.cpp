#include <iostream>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	
	long long a[N];
	for(int i = 0; i < N; i++)
	{
		std::cin >> a[i];
	}
	std::sort(a, a + N);
	
	long long last = -1;
	int count = 1;
	int best = 1;
	for(int i = 0; i < N; i++)
	{
		if(a[i] == last)
			count++;
		else
			count = 1;
		
		if(count > best)
			best = count;
		
		last = a[i];
	}
	
	std::cout << best;
	
	return 0;
}