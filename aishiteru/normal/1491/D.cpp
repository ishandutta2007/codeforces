#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,t,x,a[N],i,s,u,v,j,f[N];
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&u,&v);
		if(u>v)
		{
			puts("NO");
			continue;
		}
		for(i=30;i>=0;--i)
			if((u>>i&1)!=(v>>i&1))
				break;
		int t=__builtin_popcount(u)-__builtin_popcount(v);
		if(t<0)
		{
			puts("NO");
			continue;
		}
		for(j=i;j>=0&&t;--j)
			if((u>>j)&1)
			{
				u^=(1<<j);
				--t;
			}
		int s=0;
		for(j=i;j>=0;--j)
		{
			if((v>>j)&1)
				++s;
			if((u>>j)&1)
				--s;
			if(s<0)
				break;
		}
		if(j<0)
			puts("YES");
		else
			puts("NO");
		//puts(__builtin_popcount(u)>=__builtin_popcount(v)&&u<=v?"YES":"NO");
	}
}