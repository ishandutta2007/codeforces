#include<bits/stdc++.h>
const int maxn=1<<20;
int n,m,k;
char s[1<<20];
int a[1<<20];
int b[1<<20];
int c[1<<20];
void exec()
{
	scanf("%d%d",&n,&k);
	if(k>(n+1)/2){puts("-1");return;}
	int d=k<<1;
	for(int i=1;i<=n;i++,puts(""))
	{
		for(int ii=1;ii<=n;ii++)
		{
			if(i!=ii)putchar('.');
			else
			{
				if(i&1)
				{
					if(i<=d)putchar('R');
					else putchar('.');
				}
				else putchar('.');
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}