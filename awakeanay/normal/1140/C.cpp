#include <iostream>
#include <set>
#include <algorithm>

int main()
{
	long long n, k;
	std::cin >> n >> k;
	
	std::pair<long long, long long> songs[n];
	for(int i = 0; i < n; i++)
		std::cin >> songs[i].second >> songs[i].first;
	
	std::sort(songs, songs + n);
	
	std::set<std::pair<long long, int> > used;
	long long answer = 0;
	long long current = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(used.size() < k)
		{
			used.insert({songs[i].second, i});
			current += songs[i].second;
		}
		else
		{
			if(((*used.begin()).first) <= songs[i].second)
			{
				current += songs[i].second - ((*used.begin()).first);
				used.erase(used.begin());
				used.insert({songs[i].second, i});
			}
		}
		answer = std::max(answer, current*songs[i].first);
	}
	
	std::cout << answer;
	
	return 0;
}