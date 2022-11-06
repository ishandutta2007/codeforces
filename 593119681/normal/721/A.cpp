#include <cstdio>
#define N 100 + 5

int n, cnt, succ = 0, Ans[N];
char s[N];
bool flag = 0;

int main()
{
	scanf("%d%s", &n, s);
	s[n ++] = 'W';
	for (int i = 0; i < n; i ++)
	{
		if (s[i] == 'B')
		{
			if (!flag) flag = 1, succ = 1;
				else succ ++;
		}
		else
		{
			if (!flag) continue ;
			Ans[++ cnt] = succ;
			succ = flag = 0;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++)
		printf("%d%c", Ans[i], i == cnt ? '\n' : ' ');
	return 0;
}