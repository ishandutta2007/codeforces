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
		unsigned int a[n];
		int f[32];
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++)
		{
			unsigned int m = 0;
			for (int j = 0; j < 4; j++)
			{
				unsigned int x;
				scanf((j? ".%ud" : "%ud"), &x);
				m |= x << ((3 - j) << 3);
			}
			a[i] = m;
		}
		
		sort(a, a + n);
		for (int i = 1; i < n; i++)
		{
			for (int j = 31; j >= 0; j--)
				if ((a[i] ^ a[i - 1]) & (1U << j))
				{
					f[j]++;
					break;
				}
		}
		k -= 1;
		for (int i = 31; i >= 0 && k >= 0; i--)
		{
			k -= f[i];
			if (k == 0)
			{
				unsigned int m = (1LL << 32) - (1U << i);
				for (int j = 0; j < 4; j++)
				{
					if (j)
						printf(".");
					printf("%d", (m >> ((3 - j) << 3)) & (0xff));
				}
				printf("\n");
				break;
			}
		}
		if (k != 0)
			puts("-1");
	}
	return 0;
}