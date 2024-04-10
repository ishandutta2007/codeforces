#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)3030)
#define M ((ll)101*1000)
#define INF ((ll)1e18)

ll a,b,m,num[N],ans,c[M];
pair <ll,ll> e[N][N];
vector <pair<ll,ll> > ed;


int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>a>>b>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;v=v*2;u=u*2+1;
		num[v]++;num[u]++;
		ed.push_back({v,u});
	}
	for(int i=0;i<N;i++)ans=max(ans,num[i]);
	cout<<ans<<"\n";
	for(int i=0;i<m;i++)
	{
		ll v=ed[i].first,u=ed[i].second;
		ll col=-1;
		for(int j=0;j<ans;j++)
			if(!e[v][j].first && !e[u][j].first)
			{
				col=j;
				break;
			}
		if(col!=-1)
		{
			c[i]=col;
			e[v][col]={u,i};
			e[u][col]={v,i};
			continue;
		}
		ll c1,c2;
		for(int j=0;j<ans;j++)
		{
			if(!e[v][j].first)c1=j;
			if(!e[u][j].first)c2=j;
		}
		ll x=u;
		ll now=c1,rev=c2;
		c[i]=c1;
		e[v][c1]={u,i};
		e[u][c2]={v,i};
		while(1)
		{
		    ll new_x=e[x][now].first,id=e[x][now].second;
		    e[x][now]=e[x][rev];
		    if(new_x==0){e[x][rev].first=0;break;}
		    c[id]=rev;
		    e[x][rev]={new_x,id};
		    swap(now,rev);x=new_x;
		}
		
	}
	for(int i=0;i<m;i++)cout<<c[i]+1<<" ";
	return 0;
}