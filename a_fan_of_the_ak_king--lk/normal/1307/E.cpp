#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=1000000007;
typedef long double lb;
int n,m,p[N],t[N],i,a[N],mx,ans,s,l[N],r[N],j,k;
struct str{
	int x,y;
};
vector<str> g[N];
bool cmp(str a,str b)
{
	return a.x<b.x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	mx=0,ans=1;
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&p[i],&t[i]);
		str tmp;
		s=0;
		for(j=1;j<=n;++j)
		{
			if(p[i]==a[j])
				++s;
			if(s==t[i])
				break;
		}
		if(j>n)
			continue;
		tmp.x=j;
		s=0;
		for(j=n;j>=1;--j)
		{
			if(p[i]==a[j])
				++s;
			if(s==t[i])
				break;
		}
		tmp.y=j;
		g[p[i]].push_back(tmp);
	}
	for(i=1;i<=n;++i)
		sort(g[i].begin(),g[i].end(),cmp);
	for(i=1;i<=n;++i)
		for(auto it:g[i])
		{
			s=1;
			long long w=1;
			for(j=1;j<=n;++j)
			{
				for(k=0;k<g[j].size();++k)
					if(g[j][k].y<=it.x)
						break;
				r[j]=k;
				for(k=0;k<g[j].size();++k)
					if(g[j][k].x>=it.x)
						break;
				l[j]=k;
			}
			for(j=1;j<=n;++j)
				if(j!=i)
				{
					if(l[j]>=1&&r[j]>=1&&l[j]+r[j]>=3)
					{
						s+=2;
						w=w*(r[j]*l[j]-min(l[j],r[j]))%M;
					}
					else
						if(l[j]>=1||r[j]>=1)
						{
							++s;
							w=w*(r[j]+l[j])%M;
						}
				}
				else
					if(r[j]-(it.x<it.y)>=1)
					{
						++s;
						w=w*(r[j]-(it.x<it.y))%M;
					}
			if(mx<s)
			{
				mx=s;
				ans=0;
			}
			if(mx==s)
				ans=(ans+w)%M;
		}
	for(i=1;i<=n;++i)
		for(auto it:g[i])
		{
			s=1;
			long long w=1;
			for(j=1;j<=n;++j)
				if(i!=j)
			{
				for(k=0;k<g[j].size();++k)
					if(g[j][k].y<=it.y)
						break;
				if(k)
				{
					w=w*k%M;
					++s;
				}
			}
			if(mx<s)
			{
				mx=s;
				ans=0;
			}
			if(mx==s)
				ans=(ans+w)%M;
		}
	cout<<mx<<' '<<(ans%M+M)%M;
}