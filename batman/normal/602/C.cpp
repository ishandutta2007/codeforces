#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (555)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,a[N][N],dis[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		a[v][u]=1;
		a[u][v]=1;
	}
	if(!a[1][n])
	{
		for(int i=0;i<N;i++)dis[i]=INF;
		bool mark[N]={};
		dis[1]=0;
		ll u;
		while(1)
		{
			ll x=INF;
			u=-1;
			for(int i=0;i<n;i++)
				if(!mark[i] && x>=dis[i])
					x=dis[i],u=i;
			if(u==-1)break;
			mark[u]=1;
			for(int i=1;i<=n;i++)
				if(a[u][i] && dis[i]>dis[u]+1)
					dis[i]=dis[u]+1;
		
                }
                if(dis[n]==INF)
			return cout<<-1,0;
		cout<<dis[n];
		
		return 0;			
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					a[i][j]=(1-a[i][j]);
		for(int i=0;i<N;i++)dis[i]=INF;
		bool mark[N]={};
		dis[1]=0;
		ll u;
		while(1)
		{
			ll x=INF;
			u=-1;
			for(int i=0;i<n;i++)
				if(!mark[i] && x>=dis[i])
					x=dis[i],u=i;
			if(u==-1)break;
			mark[u]=1;
			for(int i=1;i<=n;i++)
				if(a[u][i] && dis[i]>dis[u]+1)
					dis[i]=dis[u]+1;
		}
		if(dis[n]==INF)
			return cout<<-1,0;
		cout<<dis[n];
		return 0;				
	}
	
    return 0;
}