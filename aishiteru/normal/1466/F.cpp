#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,i,t,j,m,ans[N],p,f[N],c[N],u,v;
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y&&(c[x]==0||c[y]==0))
	{
		f[x]=y;
		c[y]|=c[x];
		ans[++p]=i;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d",&u);
			if(c[Find(u)]==0)
			{
				c[Find(u)]=1;
				ans[++p]=i;
			}
		}
		else
		{
			scanf("%d %d",&u,&v);
			uniot(u,v);
		}
	}
	long long s=1;
	for(i=1;i<=p;++i)
		s=s*2%M;
	cout<<s<<' '<<p<<endl;
	for(i=1;i<=p;++i)
		printf("%d ",ans[i]);
}