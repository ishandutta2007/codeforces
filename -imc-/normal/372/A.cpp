#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	#ifdef LOCAL
	freopen ("a.in", "r", stdin);
	#endif
	
	int n;
	scanf ("%d", &n);
	
	vector <int> size (n);
	
	for (int i = 0; i < n; i++)
		scanf ("%d", &size[i]);
	
	sort (size.begin(), size.end());
	
	int minPrefix = 0, maxPrefix = n / 2;
	
	while (minPrefix != maxPrefix)
	{
		int m = (minPrefix + maxPrefix + 1) / 2;
		bool can = true;
		
		for (int i = 0; i < m; i++)
			if (size[i] * 2 > size[n - m + i])
			{
				can = false;
				break;
			}
			
		if (can)
			minPrefix = m;
		else
			maxPrefix = m - 1;
	}
	
	printf ("%d\n", n - minPrefix);
	
	return 0;
}