#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int nTests;
	scanf("%d", &nTests);
	
	for (int i = 0; i < nTests; i++)
	{
		int n, p;
		scanf("%d %d", &n, &p);
		p += 2 * n;
		
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				printf("%d %d\n", i, j);
				p--;
				if (p == 0) goto breakAll;
			}
		breakAll:;
	}
	
	return 0;
}