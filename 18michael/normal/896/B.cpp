#include<bits/stdc++.h>
using namespace std;
int n,m,c;
bool ok;
int a[1002];
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int x;;)
	{
		scanf("%d",&x);
		if(x<=c/2)
		{
			for(int i=1;i<=n;++i)
				if(!a[i] || a[i]>x)
				{
					a[i]=x,printf("%d\n",i),fflush(stdout);
					break;
				}
		}
		else
		{
			for(int i=n;i;--i)
				if(!a[i] || a[i]<x)
				{
					a[i]=x,printf("%d\n",i),fflush(stdout);
					break;
				}
		}
		ok=1;
		for(int i=1;i<=n;++i)if(!a[i])ok=0;
		if(ok)return 0;
	}
}