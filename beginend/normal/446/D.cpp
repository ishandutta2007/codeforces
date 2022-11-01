#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=505;

int n,m,k,top,tot,ma[N][N],deg[N],ty[N],id[105];
double a[N][N],g[N][N];
struct data{int ty,x,y;double w;}op[N*N];
struct Matrix{double a[105][105];}b,c,ans;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void gauss()
{
	for (int i=1;i<=n;i++)
	{
		double w=a[i][i];
		for (int j=i;j<=n;j++) a[i][j]/=w;
		op[++top]=(data){0,i,0,w};
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				w=a[j][i];
				for (int k=i;k<=n;k++) a[j][k]-=a[i][k]*w;
				op[++top]=(data){1,j,i,w};
			}
	}
}

void mul2()
{
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
			c.a[i][j]=0;
	for (int i=1;i<=tot;i++)
		for (int k=1;k<=tot;k++)
			for (int j=1;j<=tot;j++)
				c.a[i][j]+=ans.a[i][k]*b.a[k][j];
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
			ans.a[i][j]=c.a[i][j];
}

void mul1()
{
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
			c.a[i][j]=0;
	for (int i=1;i<=tot;i++)
		for (int k=1;k<=tot;k++)
			for (int j=1;j<=tot;j++)
				c.a[i][j]+=b.a[i][k]*b.a[k][j];
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
			b.a[i][j]=c.a[i][j];
}

void ksm(int y)
{
	for (int i=1;i<=tot;i++) ans.a[i][i]=1;
	while (y)
	{
		if (y&1) mul2();
		mul1();y>>=1;
	}
}

int main()
{
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) ty[i]=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		ma[x][y]++;ma[y][x]++;deg[x]++;deg[y]++;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (ma[i][j]&&!ty[j]) a[i][j]=(double)ma[i][j]/deg[i];
	for (int i=1;i<=n;i++) a[i][i]=-1;
	gauss();
	for (int i=1;i<=n;i++)
	{
		if (!ty[i]) continue;
		for (int j=1;j<=n;j++) g[j][i]=-(double)ma[j][i]/deg[j];
		for (int j=1;j<=top;j++)
			if (!op[j].ty) g[op[j].x][i]/=op[j].w;
			else g[op[j].x][i]-=g[op[j].y][i]*op[j].w;
	}
	for (int i=1;i<=n;i++) if (ty[i]) id[++tot]=i;
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
			b.a[i][j]=g[id[i]][id[j]];
	ksm(k-2);
	double an=0;
	for (int i=1;i<=tot;i++) an+=g[1][id[i]]*ans.a[i][tot];
	printf("%.8lf",an);
	return 0;
}