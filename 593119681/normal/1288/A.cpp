#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int Case, n, d;

inline int Calc(int x)
{
	int t = max(int(sqrt(x + 0.5)) - 5, 0);
	int res = x;
	for (int i = 0; i < 10; i ++)
		res = min(res, t + i + (x + t + i) / (t + i + 1));
	return res;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &d);
		int m = Calc(d);
		if (m <= n)
			puts("YES");
		else puts("NO");
	}
	return 0;
}