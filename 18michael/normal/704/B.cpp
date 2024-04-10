#include<cstdio>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
int n,s,e;LL A,B,C,D;
int x[5002],a[5002],b[5002],c[5002],d[5002];
LL f[2][5002][3];
inline LL min(LL x,LL y)
{
	return x<y? x:y;
}
inline void upd(LL &x,LL y)
{
	if(y<x)x=y;
}
int main()
{
	scanf("%d%d%d",&n,&s,&e);
	for(int i=0;i<2;++i)for(int j=0;j<=n;++j)f[i][j][0]=f[i][j][1]=f[i][j][2]=inf;f[0][0][1]=0;
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
	{
		for(int j=0;j<=n;++j)f[i1][j][0]=f[i1][j][1]=f[i1][j][2]=inf;
		for(int j=0;j<=i;++j)
			for(int k=(j? 0:1+(i>1));k<3;++k)
			{
				A=a[i]+x[i],B=b[i]-x[i],C=c[i]+x[i],D=d[i]-x[i];
				if(i==s)
				{
					if(k)upd(f[i1][j][k-1],f[i0][j][k]+C);
					if(j<i && k)upd(f[i1][j+1][k-1],f[i0][j][k]+D);
				}
				else if(i==e)
				{
					if(j && k<2)upd(f[i1][j-1][k+1],f[i0][j][k]+A);
					if(k<2)upd(f[i1][j][k+1],f[i0][j][k]+B);
				}
				else
				{
					if(j<i)upd(f[i1][j+1][k],f[i0][j][k]+B+D);
					if(j+k-1>0)upd(f[i1][j][k],f[i0][j][k]+B+C);
					if(j)upd(f[i1][j][k],f[i0][j][k]+A+D),upd(f[i1][j-1][k],f[i0][j][k]+A+C);
				}
			}
	}
	return 0&printf("%lld",f[n&1][0][1]);
}