#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
using namespace std;
struct node
{
	int a,b,d;
}e[155];
int n,m,i,j,k,x,y,f[155][155],F[155],g[155][155],ans=1<<30;
bool b[155][155],c[155][155];
bitset<155> A[155],B[155];
bool cmp(node a,node b)
{
	return a.d<b.d;
}
void mult(bool a[155][155],bool b[155][155])
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			A[i][j]=a[i][j],B[i][j]=b[j][i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=(A[i]&B[j]).count();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].d);
	sort(e+1,e+1+m,cmp);
	for(i=2;i<=n;++i)
		f[0][i]=1<<30;
	for(i=1;i<=m;++i)
	{
		for(x=1;x<=n;++x)
			for(y=1;y<=n;++y)
				b[x][y]=(x==y),c[x][y]=false;
		for(j=1;j<i;++j)
			c[e[j].a][e[j].b]=true;
		k=e[i].d-e[i-1].d;
		while(k)
		{
			if(k&1)
				mult(b,c);
			mult(c,c);
			k>>=1;
		}
		for(j=1;j<=n;++j)
			F[j]=f[i][j]=1<<30;
		for(j=1;j<=n;++j)
			if(f[i-1][j]<(1<<30))
			{
				for(k=1;k<=n;++k)
					if(b[j][k])
						F[k]=min(F[k],f[i-1][j]+e[i].d-e[i-1].d);
			}
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				g[j][k]=(j==k?0:1<<30);
		for(j=1;j<=i;++j)
			g[e[j].a][e[j].b]=min(g[e[j].a][e[j].b],1);
		for(x=1;x<=n;++x)
			for(j=1;j<=n;++j)
				for(k=1;k<=n;++k)
					g[j][k]=min(1ll*g[j][k],1ll*g[j][x]+g[x][k]);
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				f[i][k]=min(1ll*f[i][k],1ll*F[j]+g[j][k]);
		/*for(j=1;j<=n;++j)
			printf("%d ",f[i][j]);
		puts("");*/
		ans=min(ans,f[i][n]);
	}
	if(ans<(1<<30))
		printf("%d",ans);
	else
		printf("Impossible");
	return 0;
}