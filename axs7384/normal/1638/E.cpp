#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[100];
const int N=2000005;
ll f[N],sum[N];
int n,q;
inline void add(int x,ll y)
{
	for (;x<=n;x+=x&(-x))
		f[x]+=y;
}
inline ll ask(int x)
{
	ll ans=0;
	for (;x;x-=x&(-x))
		ans+=f[x];
	return ans;
}
inline void add(int l,int r,ll p)
{
	add(l,p);
	add(r,-p);
}
int l,r,x,y;
map<int,int> mp;
int main()
{
	scanf("%d%d",&n,&q);
	mp[1]=1;mp[n+1]=0;
	for (int i=1;i<=q;++i)
	{
		scanf("%s",s);
		if (s[0]=='C')
		{
			scanf("%d%d%d",&l,&r,&x);
			++r;
			auto it=--mp.upper_bound(l);
			mp[l]=it->second;
			it=--mp.upper_bound(r);
			mp[r]=it->second;
			it=mp.lower_bound(l);
			while (it->first!=r)
			{
				add(it->first,next(it)->first,sum[it->second]-sum[x]);
				mp.erase(it);
				it=mp.lower_bound(l);
			}
			mp[l]=x;
			// cout<<"?"<<l<<' '<<x<<endl;
		}
		if (s[0]=='A')
		{
			scanf("%d%d",&x,&y);
			sum[x]+=y;
		}
		if (s[0]=='Q')
		{
			scanf("%d",&x);
			auto it=--mp.upper_bound(x);
			// cout<<"?"<<x<<' '<<it->first<<' '<<it->second<<' '<<sum[1]<<' '<<sum[2]<<endl;
			printf("%lld\n",sum[it->second]+ask(x));
		}
	}
}
/*
2 100
Add 1 1
Query 1
Color 1 1 2
Query 1
Add 2 100
Query 1
Query 2

*/