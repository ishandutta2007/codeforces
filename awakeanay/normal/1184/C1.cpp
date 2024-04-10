#include <iostream>

#define MAX 51

int dx[MAX], dy[MAX];

int main()
{
	int n;
	std::cin >> n;
	n = 4*n + 1;
	
	int minX = MAX, maxX = 0, minY = MAX, maxY = 0;
	
	std::pair<int, int> p[n];
	
	for(int i = 0; i < n; i++)
	{
		std::cin >> p[i].first >> p[i].second;
		dx[p[i].first]++;
		dy[p[i].second]++;
	}
	
	for(int i = 0; i < MAX; i++)
	{
		if(dx[i] > 1)
		{
			minX = std::min(minX, i);
			maxX = std::max(maxX, i);
		}
		
		if(dy[i] > 1)
		{
			minY = std::min(minY, i);
			maxY = std::max(maxY, i);
		}
	}
	
	//std::cout << minX << " " << maxX << " " << minY << " " << maxY << std::endl;
	
	for(int i = 0; i < n; i++)
	{
		if((p[i].first > maxX || p[i].first < minX || p[i].second > maxY || p[i].second < minY) || (p[i].first != minX && p[i].second != minY && p[i].first != maxX && p[i].second != maxY))
		{
			std::cout << p[i].first << " " << p[i].second << std::endl;
			return 0;
		}
	}
	
	return 0;
}