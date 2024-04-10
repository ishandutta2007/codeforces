#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,k,f[N];
struct str{
	int u,v,w;
}e[N];
bool cmp(str a,str b)
{
	return a.w<b.w;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int x,int y)
{
	int u=Find(x),v=Find(y);
	if(u!=v)
		f[u]=v;
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
		scanf("%d %d %d",&n,&m,&k);
		for(i=1;i<=m;++i)
			scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		for(i=1;i<=n;++i)
			f[i]=0;
		sort(e+1,e+1+m,cmp);
		int s=0;
		long long ans=100000000000000ll;
		for(i=1;i<=m&&e[i].w<=k;++i)
			if(Find(e[i].u)!=Find(e[i].v))
			{
				f[Find(e[i].u)]=Find(e[i].v);
				++s;
			}
		//cout<<s<<endl;
		if(s==n-1)
		{
			if(i<=m)
				ans=min(ans,1ll*e[i].w-k);
			if(i-1>=1)
				ans=min(ans,1ll*k-e[i-1].w);
		}
		else
		{
			ans=0;
			for(;i<=m;++i)
				if(Find(e[i].u)!=Find(e[i].v))
				{
				f[Find(e[i].u)]=Find(e[i].v);
					ans+=e[i].w-k;
				}
		}
		printf("%lld\n",ans);
	}
}