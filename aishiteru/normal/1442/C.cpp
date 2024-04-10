#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=500005;
int n,m,i,j,u,v,k,s=1,head[N],Next[N*2],adj[N*2],ty[N*2],vis[N][2],l,r;
int dp[N][25][2];
struct node{
	int x,y,z;
}q2[N*26];
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	ty[k]=w;
}
struct str{
	int a,b,z,x;
}dis[N][2];
bool operator <(str a,str b)
{
	if(a.a==b.a)
		return a.b>b.b;
	return a.a>b.a;
}
priority_queue<str> q;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v,0);
		Push(v,u,1);
	}
	for(i=2;i<=n;++i)
	{
		dis[i][0].a=dis[i][0].b=1<<30;
		dis[i][1].a=dis[i][1].b=1<<30;
	}
	dis[1][1].a=dis[1][1].b=1<<30;
	q.push((str){0,0,0,1});
	while(!q.empty())
	{
		str x=q.top();
		q.pop();
		if(vis[x.x][x.z])
			continue;
		vis[x.x][x.z]=1;
		for(i=head[x.x];i;i=Next[i])
			if(ty[i]==x.z)
				if(dis[adj[i]][x.z].a>dis[x.x][x.z].a||(dis[adj[i]][x.z].a==dis[x.x][x.z].a&&dis[adj[i]][x.z].b>dis[x.x][x.z].b+1))
				{
					dis[adj[i]][x.z].a=dis[x.x][x.z].a,dis[adj[i]][x.z].b=dis[x.x][x.z].b+1;
					q.push((str){dis[adj[i]][x.z].a,dis[adj[i]][x.z].b,x.z,adj[i]});
				}
		if(dis[x.x][x.z^1].a>dis[x.x][x.z].a+1||(dis[x.x][x.z^1].a==dis[x.x][x.z].a+1&&dis[x.x][x.z^1].b>dis[x.x][x.z].b))
		{
			dis[x.x][x.z^1].a=dis[x.x][x.z].a+1;
			dis[x.x][x.z^1].b=dis[x.x][x.z].b;
			q.push((str){dis[x.x][x.z^1].a,dis[x.x][x.z^1].b,x.z^1,x.x});
		}
	}
	//cout<<dis[n][0].a<<' '<<dis[n][1].a<<endl;
	if(min(dis[n][0].a,dis[n][1].a)>=22)
	{
		if(dis[n][0].a>dis[n][1].a||(dis[n][0].a==dis[n][1].a&&dis[n][0].b>dis[n][1].b))
			swap(dis[n][0],dis[n][1]);
		int s=1;
		for(i=1;i<=dis[n][0].a;++i)
			s=s*2%M;
		cout<<(s-1+dis[n][0].b)%M;
	}
	else
	{
		memset(dp,-1,sizeof(dp));
		dp[1][0][0]=0;
		q2[l=r=1]=(node){1,0,0};
		while(l<=r)
		{
			if(q2[l].y<=23)
				for(i=head[q2[l].x];i;i=Next[i])
					if(dp[adj[i]][q2[l].y+(q2[l].z^ty[i])][ty[i]]==-1)
					{
						dp[adj[i]][q2[l].y+(q2[l].z^ty[i])][ty[i]]=dp[q2[l].x][q2[l].y][q2[l].z]+1;
						q2[++r]={adj[i],q2[l].y+(q2[l].z^ty[i]),ty[i]};
					}
			++l;
		}
		int ans=1<<30;
		for(i=0;i<=23;++i)
			if(dp[n][i][0]!=-1)
			{
				ans=min(ans,(1<<i)-1+dp[n][i][0]);
				//cout<<dp[n][i]<<' '<<i<<endl;
			}
		for(i=0;i<=23;++i)
			if(dp[n][i][1]!=-1)
			{
				ans=min(ans,(1<<i)-1+dp[n][i][1]);
				//cout<<dp[n][i]<<' '<<i<<endl;
			}
		cout<<ans;
	}
}