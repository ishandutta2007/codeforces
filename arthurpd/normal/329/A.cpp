//http://codeforces.com/problemset/problem/329/A
#include <stdio.h>

int l[112], c[112];

int
main(void)
{
	int n; char ch; bool okl = true, okc = true;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf(" %c", &ch);
			if(ch == '.')
				l[i+1] = j+1, c[j+1] = i+1;
		}
	for(int i = 1; i <= n; i++)
	{
		if(l[i] == 0) okl = false;
		if(c[i] == 0) okc = false;
	}
	if(okl)
		for(int i = 1; i <= n; i++)
			printf("%d %d\n", i, l[i]);
	else if(okc)
		for(int i = 1; i <= n; i++)
			printf("%d %d\n", c[i], i);
	else
		printf("-1\n");
}