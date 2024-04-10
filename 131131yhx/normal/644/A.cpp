#include <bits/stdc++.h>

using namespace std;

int Ans[1010][1010];

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if(n > a * b) puts("-1");
	else 
	{
		int s = n / b, Cnt = 0;
		for(int i = 1; i <= s; i++)
			if(i & 1)
				for(int j = 1; j <= b; j++) Ans[i][j] = ++Cnt;
			else
				for(int j = b; j >= 1; j--) Ans[i][j] = ++Cnt;
		if(n % b)
		{
			s++;
			if(s & 1)
				for(int j = 1; j <= b; j++)
				{
					Ans[s][j] = ++Cnt;
					if(Cnt >= n) break;
				}
				else for(int j = b; j >= 1; j--)
				{
					Ans[s][j] = ++Cnt;
					if(Cnt >= n) break;
				}
		}
		for(int i = 1; i <= a; i++)
		{
			for(int j = 1; j <= b; j++)
				printf("%d ", Ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}