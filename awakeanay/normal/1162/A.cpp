#include <iostream>

int main()
{
	long long n, h, m;
	std::cin >> n >> h >> m;

	long long a[n];
	for(int i = 0; i < n; i++)
		a[i] = h;

	for(int i = 0; i < m; i++)
	{
		int x, y;
		long long l;
		std::cin >> x >> y >> l;
		for(int i = x-1; i < y; i++)
		a[i] = std::min(l, a[i]);
	}

	long long answer = 0;
	for(int i = 0; i < n; i++)
		answer += a[i]*a[i];

	std::cout << answer;
}