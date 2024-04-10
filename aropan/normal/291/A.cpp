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
	
	do
	{
		int n, ans = 0;
		if (scanf("%d", &n) != 1)
			break;
			
		int a[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0, j = 0; i < n; i = j)
		{
			while (j < n && a[i] == a[j]) j++;
			if (a[i] == 0)
				continue;
			if (j - i > 2)
			{
				ans = -1;
				break;
			}
			ans += j - i == 2;
		}
		printf("%d\n", ans);
	} while (true);
	return 0;
}