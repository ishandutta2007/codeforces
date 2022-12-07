//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 101 * 1000

int n, q, zl[2], a, b;
int t[N];

int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		++zl[t[i]];
	}
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d", &a, &b);
		if(a&1)
		{
			if(t[b]==0)
			{
				t[b]=1;
				++zl[1];
				--zl[0];
			}
			else
			{
				t[b]=0;
				++zl[0];
				--zl[1];
			}
		}
		else
		{
			printf("%d\n", zl[1]>=b);
		}
	}
	return 0;
}