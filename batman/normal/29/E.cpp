#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (501)

ll n,m,dis[N][N][2];
vector <ll> e[N];
pair <ll,ll> par[N][N][2];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	queue <pair<pair<ll,ll>,bool> > q;
	q.push({{1,n},0});	
	dis[1][n][0]=1;
	while(q.size())
	{
		ll x=q.front().first.first,y=q.front().first.second;
		bool p=q.front().second;
		q.pop();
		if(p)
			for(int i=0;i<e[y].size();i++)
			{
				ll y2=e[y][i];
				if(y2!=x && !dis[x][y2][0])
					par[x][y2][0]={x,y},dis[x][y2][0]=dis[x][y][1]+1,q.push({{x,y2},0});
			}
		else
			for(int i=0;i<e[x].size();i++)
			{
				ll x2=e[x][i];
				if(!dis[x2][y][1])
					par[x2][y][1]={x,y},dis[x2][y][1]=dis[x][y][0]+1,q.push({{x2,y},1});
			}	
	}
	stack <ll> ans1,ans2;
	if(!dis[n][1][0]){printf("-1");return 0;}
	printf("%d\n",(dis[n][1][0]-1)/2);
	ll x=n,y=1,tmp;
	for(int i=0;i<dis[n][1][0];i+=2)
		ans2.push(y),tmp=x,x=par[x][y][(i&1)].first,y=par[tmp][y][(i&1)].second,tmp=x,x=par[x][y][((i+1)&1)].first,y=par[tmp][y][((i+1)&1)].second;	
	x=n,y=1;
	for(int i=0;i<dis[n][1][0];i+=2)
		ans1.push(x),tmp=x,x=par[x][y][(i&1)].first,y=par[tmp][y][(i&1)].second,tmp=x,x=par[x][y][((i+1)&1)].first,y=par[tmp][y][((i+1)&1)].second;	
	while(ans1.size())printf("%d ",ans1.top()),ans1.pop();
	printf("\n");	
	while(ans2.size())printf("%d ",ans2.top()),ans2.pop();
    return 0;
}