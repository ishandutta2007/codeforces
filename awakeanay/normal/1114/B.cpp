#include <iostream>
#include <algorithm>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	
	long long seq[n];
	std::pair<long long, long long> sSeq[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
		sSeq[i] = {seq[i], i};
	}
	
	std::sort(sSeq, sSeq + n);
	bool choose[n];
	for(int i = 0; i < n; i++)
		choose[i] = false;
	
	long long answer = 0;
	for(int i = 0; i < m*k; i++)
	{
		choose[sSeq[n-i-1].second] = true;
		answer += sSeq[n-i-1].first;
	}
	
	int count = 0;
	int j = 0;
	std::cout << answer << std::endl;
	for(int i = 0; i < n && j < k-1; i++)
	{
		count += choose[i];
		if(count == m)
		{
			std::cout << i+1 << " ";
			count = 0;
			j++;
		}
	}
	
	return 0;
}