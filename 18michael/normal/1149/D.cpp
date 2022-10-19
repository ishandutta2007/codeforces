#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n,m,A,B,edge_t=0,t=0,t2=0,cnt,Mx;
int la[72],rt[72],rt2[72];
int dp[131072][72];
typedef pair<int,int> P;
queue<P> qa,qb;
struct aaa
{
	int to,nx,val;
}edge[402];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x)
{
	rt2[x]=t2,++cnt;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].val==A && !rt2[v=edge[i].to])dfs(v);
}
inline void dfs1(int x)
{
	rt[x]=t;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].val==A && !rt[v=edge[i].to])dfs1(v);
}
inline void solve(P p,int a)
{
	for(int i=la[p.second],v,x;i;i=edge[i].nx)if(edge[i].val==a && (!rt[v=edge[i].to] || !((p.first>>(rt[v]-1))&1)) && dp[p.first][p.second]+a<dp[x=((rt[p.second] && rt[v]!=rt[p.second])? (p.first|(1<<(rt[p.second]-1))):p.first)][v])dp[x][v]=dp[p.first][p.second]+a,qa.push(P(x,v)),qb.push(P(x,v));
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	for(int i=1;i<=n;++i)
		if(!rt2[i])
		{
			cnt=0,++t2,dfs(i);
			if(cnt>3)++t,dfs1(i);
		}
	for(int i=1;i<=n;++i)for(int j=la[i];j;j=edge[j].nx)if(edge[j].val==B && rt2[edge[j].to]==rt2[i])edge[j].val=0;
	Mx=(1<<t);
	for(int i=0;i<Mx;++i)for(int j=1;j<=n;++j)dp[i][j]=inf;
	for(dp[0][1]=0,qa.push(P(0,1)),qb.push(P(0,1));qa.size() || qb.size();)
	{
		if(!qb.size() || (qa.size() && dp[qa.front().first][qa.front().second]+A<=dp[qb.front().first][qb.front().second]+B))solve(qa.front(),A),qa.pop();
		else solve(qb.front(),B),qb.pop();
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<Mx;++j)dp[0][i]=min(dp[0][i],dp[j][i]);
		printf("%d ",dp[0][i]);
	}
	return 0;
}