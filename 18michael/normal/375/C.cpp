#include<bits/stdc++.h>
#define inf 10000
using namespace std;
int n,m,t,tot,p,ans=0;
int val[12],dis[102402],dx[4]={-1,0,0,1},dy[4]={0,-1,1,0},sum[256];
char s[22][22];
typedef pair<int,int> P;
P pos[12];
queue<int> q;
inline int lowbit(int x)
{
	return x&(-x);
}
inline int num(int x,int y,int z)
{
	return (((x-1)*m+y-1)<<t)+z;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]>='1' && s[i][j]<='8')++t,pos[s[i][j]^48]=P(i,j);
			else if(s[i][j]=='S')pos[0]=P(i,j);
		}
	}
	for(int i=1;i<=t;++i)scanf("%d",&val[i]),sum[1<<(i-1)]=val[i];
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='B')pos[++t]=P(i,j),sum[1<<(t-1)]=val[t]=-inf;
	tot=num(n,m,(1<<t)-1);
	for(int i=0;i<=tot;++i)dis[i]=inf;
	dis[num(pos[0].first,pos[0].second,0)]=0,q.push(num(pos[0].first,pos[0].second,0));
	for(int x,y,z,nx,ny,nz;q.size();)
	{
		p=q.front(),q.pop(),x=(p>>t)/m+1,y=(p>>t)%m+1,z=p&((1<<t)-1);
		for(int i=0;i<4;++i)
			if((nx=x+dx[i])>0 && nx<=n && (ny=y+dy[i])>0 && ny<=m && (s[nx][ny]=='.' || s[nx][ny]=='S'))
			{
				nz=z;
				if(ny^y)for(int j=1;j<=t;++j)if(pos[j].second==max(y,ny) && pos[j].first<nx)nz^=1<<(j-1);
				if(dis[num(nx,ny,nz)]==inf)dis[num(nx,ny,nz)]=dis[p]+1,q.push(num(nx,ny,nz));
			}
	}
	for(int i=1;i<(1<<t);++i)sum[i]=sum[lowbit(i)]+sum[i^lowbit(i)];
	for(int i=0;i<(1<<t);++i)ans=max(ans,sum[i]-dis[num(pos[0].first,pos[0].second,i)]);
	return 0&printf("%d",ans);
}