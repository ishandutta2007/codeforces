#include <iostream>
#include <algorithm>

bool check(int m, long long seq[], long long h)
{
	long long temp[m];
	for(int i = 0; i < m; i++)
		temp[i] = seq[i];
	std::sort(temp, temp + m);
	long long sum = 0;
	for(int i = m-1; i >= 0; i -= 2)
		sum += temp[i];
	return sum <= h;
}

int main()
{
	int n; long long h;
	std::cin >> n >> h;
	
	long long seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
	
	int l = 1; int r = n;
	
	while(l < r-1)
	{
		int m = (l + r)/2;
		if(check(m, seq, h))
			l = m;
		else
			r = m;
	}
	
	while(r >= l)
	{
		if(check(r, seq, h))
		{
			std::cout << r;
			break;
		}
		r--;
	}
	
	return 0;
}