#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(!b)
		{
			if(a)
			{
				for(int i = 1; i <= a + 1; i++)
					putchar('0');
				putchar('\n');
			}
			else if(c)
			{
				for(int i = 1; i <= c + 1; i++)
					putchar('1');
				putchar('\n');
			}
		}
		else
		{
			b--;
			for(int i = 1; i <= a + 1; i++)
				putchar('0');
			for(int i = 1; i <= c + 1; i++)
				putchar('1');
			for(int i = 1, ch = 0; i <= b; i++, ch = 1 - ch)
				putchar(ch + '0');
			putchar('\n');
		}
	}
	return 0;
}