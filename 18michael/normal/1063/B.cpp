#include<cstdio>
#include<queue>
using namespace std;
int n,m,r,c,mx,my,ans=0;
bool u[2002][2002]={},v[2002][2002]={},ins[2002][2002]={};
char ch[2002];
typedef pair<int,int> P;
P p;queue<P> q;
struct aaa
{
	int mx,my;
}dis[2002][2002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline void bfs(int x,int y,int mx,int my)
{
	int sx,sy,nx,ny;
	dis[x][y]=(aaa){mx,my},q.push(P(x,y)),ins[x][y]=1;
	while(!q.empty())
	{
		p=q.front(),q.pop(),sx=p.first,sy=p.second,ins[sx][sy]=0;
		if(!u[sx][sy])u[sx][sy]=1,++ans;
		nx=sx-1,ny=sy;
		if(nx>0 && nx<=n && ny>0 && ny<=m && !v[nx][ny] && !(dis[sx][sy].mx<=dis[nx][ny].mx && dis[sx][sy].my<=dis[nx][ny].my))
		{
			dis[nx][ny]=dis[sx][sy];
			if(!ins[nx][ny])q.push(P(nx,ny)),ins[nx][ny]=1;
		}
		nx=sx+1,ny=sy;
		if(nx>0 && nx<=n && ny>0 && ny<=m && !v[nx][ny] && !(dis[sx][sy].mx<=dis[nx][ny].mx && dis[sx][sy].my<=dis[nx][ny].my))
		{
			dis[nx][ny]=dis[sx][sy];
			if(!ins[nx][ny])q.push(P(nx,ny)),ins[nx][ny]=1;
		}
		nx=sx,ny=sy-1;
		if(nx>0 && nx<=n && ny>0 && ny<=m && !v[nx][ny] && dis[sx][sy].mx && !(dis[sx][sy].mx-1<=dis[nx][ny].mx && dis[sx][sy].my<=dis[nx][ny].my))
		{
			dis[nx][ny]=dis[sx][sy],--dis[nx][ny].mx;
			if(!ins[nx][ny])q.push(P(nx,ny)),ins[nx][ny]=1;
		}
		nx=sx,ny=sy+1;
		if(nx>0 && nx<=n && ny>0 && ny<=m && !v[nx][ny] && dis[sx][sy].my && !(dis[sx][sy].mx<=dis[nx][ny].mx && dis[sx][sy].my-1<=dis[nx][ny].my))
		{
			dis[nx][ny]=dis[sx][sy],--dis[nx][ny].my;
			if(!ins[nx][ny])q.push(P(nx,ny)),ins[nx][ny]=1;
		}
	}
}
int main()
{
	read(n),read(m),read(r),read(c),read(mx),read(my);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ch+1);
		for(int j=1;j<=m;++j)v[i][j]=(ch[j]=='*'),dis[i][j]=(aaa){-1,-1};
	}
	bfs(r,c,mx,my),printf("%d",ans);
	return 0;
}