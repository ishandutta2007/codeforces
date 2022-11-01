#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=15;
const int M=2005;
const int S=4105;

int n,m,col[M],a[N][M],id[M],bin[N],w[N][S],f[N][S],nx[S][N],mx[N][S];

void clear()
{
	memset(col,0,sizeof(col));
	memset(w,0,sizeof(w));
	memset(f,0,sizeof(f));
	memset(nx,0,sizeof(nx));
	memset(mx,0,sizeof(mx));
}

bool cmp(int x,int y)
{
	return col[x]>col[y];
}

void init()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),col[j]=std::max(col[j],a[i][j]);
	for (int i=1;i<=m;i++) id[i]=i;
	std::sort(id+1,id+m+1,cmp);
	std::sort(id+1,id+std::min(n,m)+1);
	for (int j=1;j<=std::min(n,m);j++)
		for (int i=1;i<=n;i++)
			a[i][j]=a[i][id[j]];
	m=std::min(n,m);
}

int get(int x)
{
	return std::lower_bound(bin,bin+n+1,x)-bin;
}

void pre()
{
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=0;i<bin[n];i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (i&bin[k]) nx[i][j]+=bin[(k+j)%n];
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<bin[n];j++)
			w[i][j]=w[i][j-(j&(-j))]+a[get(j&(-j))+1][i];
		for (int j=1;j<bin[n];j++)
			for (int k=0;k<n;k++)
				mx[i][j]=std::max(mx[i][j],w[i][nx[j][k]]);
	}
}

void dp()
{
	for (int i=1;i<=m;i++)
		for (int j=0;j<bin[n];j++)
		{
			f[i][j]=f[i-1][j];
			for (int k=j;k;k=(k-1)&j) f[i][j]=std::max(f[i][j],f[i-1][j-k]+mx[i][k]);
		}
	printf("%d\n",f[m][bin[n]-1]);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		init();
		pre();
		dp();
		clear();
	}
	return 0;
}