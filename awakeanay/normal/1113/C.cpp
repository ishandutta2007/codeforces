#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		if(i > 0)
			a[i] ^= a[i-1];
	}
	
	int max = 1 << 20;
	int store[2][max + 1];
	for(int i = 0; i <= max; i++)
		store[0][i] = store[1][i] = 0;
	
	long long answer = 0;
	for(int i = 0; i < n; i++)
	{
		//std::cout << a[i] << " ";
		answer += store[i%2][a[i]];
		store[i%2][a[i]]++;
		if(i%2 && a[i] == 0)
			answer++;
	}
	
	//std::cout << std::endl;
	std::cout << answer;
	
	return 0;
}