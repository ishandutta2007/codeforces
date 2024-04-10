#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)2020)
#define INF ((ll)1e18)

int n;
ll e[N][N],dis[N],mini[N],min_e=INF;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		mini[i]=INF;
		for(int j=i+1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);e[i][j]=e[j][i]=x;
			min_e=min(min_e,e[i][j]);
		}
			
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(i!=j)
				e[i][j]-=min_e,mini[i]=min(mini[i],e[i][j]);
		for(int j=1;j<=n;j++)
			e[i][j]=min(e[i][j],mini[i]*2);
	}
	set <pair<ll,ll> > s;
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		if(mini[i]==0)
			dis[i]=0,s.insert({0,i});
	}
	while(s.size())
	{
		ll x=s.begin()->second;s.erase(s.begin());
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[x]+e[i][x])
				s.erase({dis[i],i}),
				dis[i]=dis[x]+e[i][x],
				s.insert({dis[i],i});
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]+(n-1)*min_e<<"\n";
	return 0;
}