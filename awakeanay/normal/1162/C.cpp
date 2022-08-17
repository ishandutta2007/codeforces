#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int appf[n+1];
	int appl[n+1];
	for(int i = 1; i <= n; i++)
	{
		appf[i] = k+1;
		appl[i] = -1;
	}
	
	for(int i = 0; i < k; i++)
	{
		int a;
		std::cin >> a;
		appf[a] = std::min(appf[a], i);
		appl[a] = std::max(appl[a], i);
	}

	int answer = 0;
	for(int i = 1; i <= n-1; i++)
		answer += (appf[i] > appl[i+1]);

	for(int i = 2; i <= n; i++)
		answer += (appf[i] > appl[i-1]);

	for(int i = 1; i <= n; i++)
		answer += (appf[i] > appl[i]);

	std::cout << answer;
}