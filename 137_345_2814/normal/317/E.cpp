#include<cstdio>
#include<cstring>
using namespace std;
#define N 205
int s1,s2,t1,t2,m,a,b,is[N][N],fr[N][N],ct,d[4][2]={-1,0,1,0,0,-1,0,1},f1[N][N];
char di[6]="LRDU";
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+d[i][0],ny=y+d[i][1];
		if(nx<0||ny<0||nx>202||ny>202||fr[nx][ny]||is[nx][ny])continue;
		f1[nx][ny]=i^1;
		fr[nx][ny]=fr[x][y];dfs(nx,ny);
	}
}
void doit(int s)
{
	printf("%c",di[s]);
	s1+=d[s][0];s2+=d[s][1];
	int nx=t1+d[s][0],ny=t2+d[s][1];
	if(nx<0||ny<0||nx>202||ny>202||!is[nx][ny])t1=nx,t2=ny;
}
bool chk1(int x,int y){return ((x<=0||x>=202)||(y<=0||y>=202));}
void fuc1(int s){if(chk1(s1+d[s][0],s2+d[s][1])&&chk1(t1+d[s][0],t2+d[s][1]))doit(s);}
int main()
{
	scanf("%d%d%d%d%d",&s1,&s2,&t1,&t2,&m);
	if(!m){printf("-1\n");return 0;}
	s1+=101;s2+=101;t1+=101;t2+=101;
	while(m--)scanf("%d%d",&a,&b),is[a+101][b+101]=1;
	for(int i=0;i<=202;i++)
	for(int j=0;j<=202;j++)if(!fr[i][j]&&!is[i][j])fr[i][j]=++ct,dfs(i,j);
	if(fr[s1][s2]!=fr[t1][t2]){printf("-1\n");return 0;}
	if(fr[s1][s2]==1)
	{
		while(!((s1<=0||s1>=202)||(s2<=0||s2>=202)))doit(f1[s1][s2]);
		for(int i=0;i<500;i++)doit(3);
		while(!((t1<=0||t1>=202)||(t2<=0||t2>=202)))doit(f1[t1][t2]);
		for(int i=1;i<=345;i++)fuc1(3);for(int i=1;i<=345;i++)fuc1(1);for(int i=1;i<=345;i++)fuc1(3);for(int i=1;i<=345;i++)fuc1(0);for(int i=1;i<=345;i++)fuc1(3);
		if(s1<t1)while(t1>=0)doit(0);else while(t1<=202)doit(1);
		if(s2<t2)while(t2>=0)doit(2);else while(t2<=202)doit(3);
		int tx=-1,ty;
		for(int i=0;i<=202;i++)
		for(int j=0;j<=202;j++)if(tx==-1)
		{
			int sx=i,sy=j;
			if(s1>=t1)sx=202-sx;
			if(s2>=t2)sy=202-sy;
			if(is[sx][sy])tx=sx,ty=sy;
		}
		if(s1<t1)
		{
			while(t2<ty)doit(3);
			while(t2>ty)doit(2);
			while(s1<tx-1)doit(1);
			for(int i=0;i<200;i++)doit(0);
			
		}
		else
		{
			while(t2>ty)doit(2);
			while(t2<ty)doit(3);
			while(s1>tx+1)doit(0);
			for(int i=0;i<200;i++)doit(1);
		}
		if(s2<t2)for(int i=0;i<200;i++)doit(2);
		else for(int i=0;i<200;i++)doit(3);
		if(s2<t2)
		{
			while(t1>tx)doit(0);
			while(t1<tx)doit(1);
			while(s2>ty+1)doit(2);
			while(s2<ty-1)doit(3);
		}
		else
		{
			while(t1>tx)doit(0);
			while(t1<tx)doit(1);
			while(s2>ty+1)doit(2);
			while(s2<ty-1)doit(3);
		}
	}
	else
	{
		while(s1!=t1||s2!=t2)
		{
			memset(fr,0,sizeof(fr));
			memset(f1,0,sizeof(f1));
			fr[t1][t2]=1;dfs(t1,t2);
			int v1=t1,v2=t2;
			while(s1!=v1||s2!=v2)doit(f1[s1][s2]);
		}
	}
}