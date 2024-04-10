#include<bits/stdc++.h>
using namespace std; 
const int N=100005,M=533;
const long double PI=3.1415926535897932384626;
int n,m,i,t,f[N],x,y;
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
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
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
			f[i]=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&x,&y);
			if(x==y)
			{
				--m;
				--i;
				continue;
			}
			else
				uniot(x,y);
		}
		int s=0;
		for(i=1;i<=n;++i)
			if(Find(i)==i)
				++s;
		printf("%d\n",m+m-(n-s));
	}
}