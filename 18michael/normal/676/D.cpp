#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,sx,sy,ex,ey,nx,ny,S,Mx,ans=inf;
int dis[4000002];
char s[1002][1002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
vector<int> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int num(int x,int y,int z)
{
	return ((x-1)*m+y-1)*4+z;
}
inline bool calc(int a,int b,int c,int d,int typ)
{
	if(!typ && a)return 1;
	if(typ==1 && b)return 1;
	if(typ==2 && c)return 1;
	if(typ==3 && d)return 1;
	return 0;
}
inline bool check(int i,int j,int x,int y,int k)
{
	if(s[i][j]=='+')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,1,1,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,1,1,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,1,1,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,1,1,1,k);
	}
	else if(s[i][j]=='-')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(0,1,0,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(0,1,0,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,0,1,0,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,0,1,0,k);
	}
	else if(s[i][j]=='|')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,0,1,0,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,0,1,0,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(0,1,0,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(0,1,0,1,k);
	}
	else if(s[i][j]=='^')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,0,0,0,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(0,0,1,0,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(0,0,0,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(0,1,0,0,k);
	}
	else if(s[i][j]=='>')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(0,0,0,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(0,1,0,0,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(0,0,1,0,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,0,0,0,k);
	}
	else if(s[i][j]=='<')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(0,1,0,0,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(0,0,0,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,0,0,0,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(0,0,1,0,k);
	}
	else if(s[i][j]=='v')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(0,0,1,0,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,0,0,0,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(0,1,0,0,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(0,0,0,1,k);
	}
	else if(s[i][j]=='L')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,0,1,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,1,1,0,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(0,1,1,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,1,0,1,k);
	}
	else if(s[i][j]=='R')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,1,1,0,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,0,1,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,1,0,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(0,1,1,1,k);
	}
	else if(s[i][j]=='U')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(0,1,1,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(1,1,0,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,1,1,0,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,0,1,1,k);
	}
	else if(s[i][j]=='D')
	{
		nx=i-1,ny=j;if(x==nx && y==ny)return calc(1,1,0,1,k);
		nx=i+1,ny=j;if(x==nx && y==ny)return calc(0,1,1,1,k);
		nx=i,ny=j-1;if(x==nx && y==ny)return calc(1,0,1,1,k);
		nx=i,ny=j+1;if(x==nx && y==ny)return calc(1,1,1,0,k);
	}
}
inline void add(int x,int y,int z,int w,int a,int b,int c,int d,int typ)
{
	if(!typ)
	{
		if(a && check(z,w,x,y,0))
			vec.push_back(num(z,w,0));
	}
	else if(typ==1)
	{
		if(b && check(z,w,x,y,1))
			vec.push_back(num(z,w,1));
	}
	else if(typ==2)
	{
		if(c && check(z,w,x,y,2))
			vec.push_back(num(z,w,2));
	}
	else if(typ==3)
	{
		if(d && check(z,w,x,y,3))
			vec.push_back(num(z,w,3));
	}
}
inline void find(int u)
{
	int i=u/4/m+1,j=((u/4)%m)+1,k=u%4;
	vec.clear();
	if(s[i][j]=='*')return ;
	vec.push_back(num(i,j,(k+1)%4));
	if(s[i][j]=='+')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,1,k);
	}
	else if(s[i][j]=='-')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,0,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,0,k);
	}
	else if(s[i][j]=='|')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,0,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,0,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,1,k);
	}
	else if(s[i][j]=='^')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,0,0,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,1,0,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,0,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,0,k);
	}
	else if(s[i][j]=='>')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,0,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,0,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,1,0,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,0,0,k);
	}
	else if(s[i][j]=='<')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,0,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,0,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,0,0,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,1,0,k);
	}
	else if(s[i][j]=='v')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,1,0,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,0,0,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,0,0,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,0,0,1,k);
	}
	else if(s[i][j]=='L')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,0,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,1,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,0,1,k);
	}
	else if(s[i][j]=='R')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,0,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,0,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,1,1,k);
	}
	else if(s[i][j]=='U')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,1,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,0,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,0,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,1,k);
	}
	else if(s[i][j]=='D')
	{
		nx=i-1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,0,1,k);
		nx=i+1,ny=j;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,0,1,1,1,k);
		nx=i,ny=j-1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,0,1,1,k);
		nx=i,ny=j+1;if(nx && ny && nx<=n && ny<=m)add(i,j,nx,ny,1,1,1,0,k);
	}
}
inline void dijkstra()
{
	for(int i=0;i<=Mx;++i)dis[i]=inf;
	int u;pq.push(P(dis[S]=0,S));
	while(!pq.empty())
	{
		p=pq.top(),pq.pop(),u=p.second;
		if(p.first>dis[u])continue;
		find(u);
		for(int i=0,v;i<vec.size();++i)
			if(dis[v=vec[i]]>dis[u]+1)
				pq.push(P(dis[v]=dis[u]+1,v));
	}
}
int main()
{
	read(n),read(m),Mx=num(n,m,3);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	read(sx),read(sy),read(ex),read(ey),S=num(sx,sy,0),dijkstra();
	for(int i=0;i<4;++i)ans=min(ans,dis[num(ex,ey,i)]);
	printf("%d",ans==inf? -1:ans);
	return 0;
}