#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int first = 0, second = 0;
	
	vector<int> central;
	
	for (int i = 0; i < n; i++)
	{
		int nThis;
		scanf("%d", &nThis);
		
		for (int j = 0; j < nThis; j++)
		{
			int x;
			scanf("%d", &x);
			
			if (j == (nThis - 1) / 2 && nThis % 2 == 1)
				central.push_back(x);
			else if (j < nThis / 2)
				first += x;
			else
				second += x;
		}
	}
	
	sort(central.begin(), central.end());
	
	for (int i = central.size() - 1; i >= 0; i--)
		if (i % 2 == ((int)central.size() - 1) % 2)
			first += central[i];
		else
			second += central[i];
		
	printf("%d %d\n", first, second);

	return 0;
}