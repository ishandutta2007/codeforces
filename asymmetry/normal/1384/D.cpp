#include <bits/stdc++.h>

using namespace std;

int gh, n, a, b;
int t[100001];
int z[100];

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		for(int i=40; i>=0; --i)
		{
			z[i]=0;
		}
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
			a=0;
			b=t[i];
			while(b)
			{
				if(b&1)
				{
					++z[a];
				}
				++a;
				b>>=1;
			}
		}
		a=2;
		for(int i=40; i>=0; --i)
		{
			if(z[i]%4==1)
			{
				a=1;
				break;
			}
			if(z[i]%4==3)
			{
				if(n&1)
				{
					a=0;
				}
				else
				{
					a=1;
				}
				break;
			}
		}
		if(!a)
		{
			printf("LOSE\n");
		}
		if(a==1)
		{
			printf("WIN\n");
		}
		if(a==2)
		{
			printf("DRAW\n");
		}
	}
	return 0;
}