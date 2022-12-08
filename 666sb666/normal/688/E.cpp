#include<cstdio>
#include<cstring>
const int maxn=600;
int n,m,c[maxn],f[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=c[i];j--)
			for(int k=j;k>=0;k--)
				if(k>=c[i])f[j][k]=f[j][k]|f[j-c[i]][k-c[i]]|f[j-c[i]][k];
				else f[j][k]=f[j][k]|f[j-c[i]][k];
	int tot=0;
	for(int i=0;i<=m;i++)if(f[m][i])tot++;
	printf("%d\n",tot);
	for(int i=0;i<=m;i++)if(f[m][i])printf("%d ",i);
	return 0;
}