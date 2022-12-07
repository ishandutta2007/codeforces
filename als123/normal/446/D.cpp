#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=505;
int n,m,k;
int t[N];
int d[N];
int mp[N][N];
double a[N][N];
struct qq
{
	int x,y,op;
	double w;
	qq () {}
	qq (int _op,int _x,int _y,double _w)	{x=_x;y=_y;op=_op;w=_w;	}
}w[N*N];int tot=0;
void Gauss ()
{
	for (int u=1;u<=n;u++)
	{
		double x=a[u][u];
		for (int i=u;i<=n;i++) a[u][i]/=x;
		w[++tot]=qq(0,u,0,x);
		for (int i=1;i<=n;i++)
		if (u!=i)
		{
			x=a[i][u];
			for (int j=u;j<=n;j++)
				a[i][j]-=a[u][j]*x;
			w[++tot]=qq(1,i,u,x);
		}
	}
}
double g[N][N];
int id[N],o;
struct qt
{
	double a[105][105];
}ans,b;
qt operator * (qt x,qt y)
{
	qt c;
	memset(c.a,0,sizeof(c));
	for (int u=1;u<=o;u++)
	for (int i=1;i<=o;i++)
	for (int j=1;j<=o;j++)
	c.a[u][i]=c.a[u][i]+x.a[u][j]*y.a[j][i];
	return c;
}
qt zero;
qt Pow (qt x,int y)
{
	if (y==0) return zero;
	if (y==1) return x;
	qt lalal=Pow(x,y>>1);
	lalal=lalal*lalal;
	if (y&1) lalal=lalal*x;
	return lalal;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int u=1;u<=n;u++) scanf("%d",&t[u]);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
		mp[x][y]++;mp[y][x]++;
	}
	for (int u=1;u<=n;u++)
	for (int i=1;i<=n;i++)
	if (mp[u][i]&&!t[i])
	a[u][i]=(double)mp[u][i]/d[u];
	for (int u=1;u<=n;u++) a[u][u]=-1;
	Gauss();
	//for (int u=1;u<=tot;u++) printf("%d %d %d %lf\n",w[u].op,w[u].x,w[u].y,w[u].w);
	for (int u=1;u<=n;u++)
	if (t[u])
	{
		for (int i=1;i<=n;i++) g[i][u]=-(double)mp[u][i]/d[i];
		for (int i=1;i<=tot;i++)
		{
			if (!w[i].op) g[w[i].x][u]/=w[i].w;
			else g[w[i].x][u]-=g[w[i].y][u]*w[i].w;
		}
	}
	for (int u=1;u<=n;u++) if (t[u]) id[++o]=u;
	for (int u=1;u<=o;u++)
	for (int i=1;i<=o;i++)
	{
	//	printf("%lf\n",g[id[u]][id[i]]);
		b.a[u][i]=g[id[u]][id[i]];
	}
	for (int u=1;u<=o;u++) zero.a[u][u]=1;
	/*for (int u=1;u<=o;u++)
	{
		for (int i=1;i<=o;i++)
		printf("%lf ",b.a[u][i]);
		printf("\n");
	}*/
	b=Pow(b,k-2);
	/*for (int u=1;u<=o;u++)
	{
		for (int i=1;i<=o;i++)
		printf("%lf ",b.a[u][i]);
		printf("\n");
	}*/
	double ans=0;
	for (int u=1;u<=o;u++) ans=ans+g[1][id[u]]*b.a[u][o];
	printf("%lf\n",ans);
	return 0;
}