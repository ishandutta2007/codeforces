#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10086

int res;
char s[N];

int main()
{
	scanf("%s", s);
	for (int i = 0, cur = 0, f = 1; ; i ++)
	{
		if (s[i] == '+' || s[i] == '-' || !s[i])
		{
			res += cur * f;
			if (!s[i]) break ;
			cur = s[i] - '0';
			f = s[i] == '+' ? 1 : -1;
		}
		else cur = cur * 10 + s[i] - '0';
	}
	printf("%d\n", res);
	return 0;
}