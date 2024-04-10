#include<bits\stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,tot,edge_t=0,nx,ny,p,now=1,to,F;int ok[2]={};
int dis[10002],la[10002]={},dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
char s[102][102];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[40002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline void dijkstra()
{
	for(int i=1;i<=tot;++i)dis[i]=inf;
	dis[F]=0,q.push(F);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p];i;i=edge[i].nx)
			if(dis[edge[i].to]==inf)
				dis[edge[i].to]=dis[p]+1,q.push(edge[i].to);
	}
}
int main()
{
	read(n),read(m),tot=n*m;
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='F')
			{
				F=num(i,j);
				break;
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='.' || s[i][j]=='F')
				for(int k=0;k<4;++k)
				{
					nx=i+dx[k],ny=j+dy[k];
					if(nx && ny && nx<=n && ny<=m && (s[nx][ny]=='.' || s[nx][ny]=='F'))
						add_edge(num(i,j),num(nx,ny));
				}
	dijkstra();
	for(int i=1,j=1;now!=F;)
	{
		for(int k=0;k<4;++k)
		{
			nx=i+dx[k],ny=j+dy[k];
			if(nx && ny && nx<=n && ny<=m && dis[num(nx,ny)]==dis[num(i,j)]-1)
			{
				to=num(nx,ny);
				break;
			}
		}
		if((now-1)/m==(to-1)/m)
		{
			if(ok[0])cout<<(((ok[0]>0)^(to>now))? "L":"R")<<endl,fflush(stdout),cin>>i>>j,now=num(i,j);
			else cout<<"R"<<endl,fflush(stdout),cin>>i>>j,ok[0]=(dis[num(i,j)]==dis[now]-1? 1:-1),now=num(i,j);
		}
		else
		{
			if(ok[1])cout<<(((ok[1]>0)^(to>now))? "U":"D")<<endl,fflush(stdout),cin>>i>>j,now=num(i,j);
			else cout<<"D"<<endl,fflush(stdout),cin>>i>>j,ok[1]=(dis[num(i,j)]==dis[now]-1? 1:-1),now=num(i,j);
		}
	}
	return 0;
}