#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=505;
const double eps=1e-7;
int n,K;
int s[N];
struct qq
{
	int x,y,z,last;
}e[N*2];int num,last[N];
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
double a[1005][N];
int tot=0;
void dfs (int x,int fa,LL dep,int id)// 
{
	//printf("YES:%d %d %d\n",x,dep,id);
	if (dep>K) return ;
	tot=tot+s[x];
	if (s[x]==1) a[id][x]=-1;
	else a[id][x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs(y,x,dep+e[u].z,id);
	}
}
int m;
int cmpd (double x)
{
	if (x<-eps) return -1;
	if (x>eps) return 1;
	return 0;
}
void divert (int r,int c)
{
	double x=-a[r][c];a[r][c]=-1;
	for (int u=0;u<=n;u++) a[r][u]=a[r][u]/x;
	for (int u=0;u<=m;u++)
		if (cmpd(a[u][c])!=0&&u!=r)
		{
			x=a[u][c];a[u][c]=0;
			for (int i=0;i<=n;i++) a[u][i]=a[u][i]+x*a[r][i];
		}
}
void solve ()
{
	while (true)
	{
		int x=0,y=0;
		for (int u=1;u<=m;u++)
			if (cmpd(a[u][0])<0)
				{x=u;break;}
		if (x==0) break;
		for (int u=1;u<=n;u++)
			if (cmpd(a[x][u])>0)
				{y=u;break;}
		if (y==0)	{printf("-1\n");return ;}
		divert(x,y);
		/*for (int u=0;u<=m;u++)
		{
			for (int i=0;i<=n;i++)
				printf("%lf ",a[u][i]);
			printf("\n");
		}
		system("pause");*/
	}
	while (true)
	{
		int x=0,y=0;
		for (int u=1;u<=n;u++)
			if (cmpd(a[0][u])>0)
				{x=u;break;}
		if (x==0) break;
		bool tf=false;
		double w,t;
		for (int u=1;u<=m;u++)
			if (cmpd(a[u][x])<0)
			{
				t=-a[u][0]/a[u][x];
				if (tf==false||t<w)	{y=u;w=t;tf=true;}
			}
		if (y==0)	{printf("-1\n");return ;}
		divert(y,x);
	}
	if (cmpd(a[0][0])==0) printf("0\n");
	else printf("%.0lf\n",-a[0][0]/2);
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&K);
	for (int u=1;u<=n;u++) a[0][u]=-1;
	for (int u=1;u<=n;u++) scanf("%d",&s[u]);
	for (int u=1;u<n;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		init(x,y,z);init(y,x,z);
	}
	m=0;
	for (int u=1;u<=n;u++)
	{
		tot=0;m++;
		dfs(u,0,0,m);
		a[m][0]=tot-1;
	}
	m++;a[m][0]=0;
	for (int u=1;u<=n;u++)
	{
		if (s[u]==1) a[m][u]=1;
		else a[m][u]=-1;
	}
	m++;a[m][0]=0;
	for (int u=1;u<=n;u++)
	{
		if (s[u]==1) a[m][u]=-1;
		else a[m][u]=1;
	}
	for (int u=1;u<=n;u++)
	{
		m++;
		a[m][0]=1;
		a[m][u]=-1;
	}
	/*for (int u=0;u<=m;u++)
	{
		for (int i=0;i<=n;i++)
			printf("%.3lf ",a[u][i]);
		printf("\n");
	}*/
	solve();
	return 0;
}