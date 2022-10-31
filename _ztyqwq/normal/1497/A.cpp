#include <bits/stdc++.h>
using namespace std;
int b[101];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			b[a]++;
		}
		for(int i = 0; i <= 100; i++)
		{
			if(b[i])
				printf("%d ", i), b[i]--;
		}
		for(int i = 0; i <= 100; i++)
			while(b[i]--)
				printf("%d ", i);
		putchar('\n');
	}
	return 0;
}