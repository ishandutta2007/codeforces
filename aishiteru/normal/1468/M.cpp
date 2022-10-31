#include<bits/stdc++.h>
using namespace std; 
const int N=300005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,j,t,k,a,ans,d[N],id[N],rk[N],c[N],tp;
map<int,int> mp;
vector<int> g[N],p[N];
bool cmp(int x,int y)
{
	return d[x]<d[y];
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
		scanf("%d",&n);
		k=0;
		mp.clear();
		for(i=1;i<=n;++i)
		{
			scanf("%d",&tp);
			for(j=1;j<=tp;++j)
			{
				scanf("%d",&a); 
				if(mp[a])
					a=mp[a];
				else
					a=mp[a]=++k;
				g[i].push_back(a+n);
				g[a+n].push_back(i);
				++d[i],++d[a+n];
			}
		}
		for(i=1;i<=n+k;++i)
			id[i]=i;
		sort(id+1,id+1+n+k,cmp);
		for(i=1;i<=n+k;++i)
			rk[id[i]]=i;
		for(i=1;i<=n+k;++i)
			for(auto it:g[i])
				if(rk[it]<rk[i])
					p[i].push_back(it);
		bool flag=true;
		for(i=1;i<=n+k;++i)
		{
			int u=i;
			for(auto v:p[u])
			{
				for(auto w:g[v])
				{
					if(w!=u)
					{
						if(c[w])
						{
							if(c[w]<=n)
								printf("%d %d\n",c[w],v);
							else
								printf("%d %d\n",u,w);
							flag=false;
							break;
						}
						c[w]=v;
					}
				}
				if(!flag)
					break;
			}
			for(auto v:p[u])
				for(auto w:g[v])
					c[w]=0;
		}
		if(flag)
			puts("-1");
		for(i=1;i<=n+k;++i)
		{
			g[i].clear();
			p[i].clear();
			d[i]=0;
		}
	}
}