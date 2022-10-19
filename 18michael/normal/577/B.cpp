#include<cstdio>
int n,m;
int a[1000002];
int f[2][1002]={};
int main()
{
	scanf("%d%d",&n,&m),f[0][0]=f[1][0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]%=m;
	for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
	{
		for(int j=1;j<=m;++j)f[i1][j]=(f[i0][j]|f[i0][(j-a[i]+m-1)%m+1]|f[i0][(j-a[i]+m)%m]);
		if(f[i1][m])return 0&puts("YES");
	}
	return 0&puts("NO");
}