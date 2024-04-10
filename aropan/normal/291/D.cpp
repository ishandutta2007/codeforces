#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	int n, k;
	while (scanf("%d %d", &n, &k) == 2)
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j)
				{
					printf(" ");
				}
				
				if (n - (1 << i) - 1 <= j)
				{
					printf("%d", n);
				} else {
					printf("%d", max(n - ((n - (1 << i) - 1) - j), n - (1 << i)));
				}
			}
			printf("\n");
		}
	}
	
	
	
	return 0;
}