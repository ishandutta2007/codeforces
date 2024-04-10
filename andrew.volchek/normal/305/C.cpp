#include <cstdio>
#include <map>

using namespace std;
map < int, int > m;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		m[x]++;
	}
	
	
	
	for (map < int, int > :: iterator it = m.begin(); it != m.end(); it++)
	{
		int curr = it->second;
		int currp = it->first;
		if (curr > 1)
		{
			m[currp+1] += curr / 2;
			it->second = curr % 2;
		}
	}
	
	int maxp = m.rbegin()->first;
	int ans = maxp - m.size();
	
	for (map < int, int > :: iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second == 0)
		{
			ans++;
		}
	}
	printf("%d", ans+1);
	return 0;
}