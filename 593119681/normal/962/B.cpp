#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, a, b, ans;
char s[N];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s + 1);
	for (int i = 1, last = 0; i <= n; i ++)
	{
		if (s[i] == '*') last = 0;
		else if (i == 1)
		{
			if (a > b)
				last = 1, ans ++, s[i] = 'A', a --;
			else if (b > 0)
				last = 2, ans ++, s[i] = 'B', b --;
		}
		else if (last != 1 && a > 0 && (a >= b || last == 2))
			last = 1, ans ++, s[i] = 'A', a --;
		else if (last != 2 && b > 0 && (b >= a || last == 1))
			last = 2, ans ++, s[i] = 'B', b --;
		else last = 0;
	}
	printf("%d\n", ans);
	return 0;
}