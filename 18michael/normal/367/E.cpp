#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,X,i0=0,i1=1;
int f[2][322][322];
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&X);
	if(n>m)return 0&puts("0");
	f[0][0][0]=1;
	for(int i=1;i<=m;++i,i0^=1,i1^=1)
	{
		for(int j=0;j<=n;++j)for(int k=0;k<=j;++k)f[i1][j][k]=0;
		for(int j=0;j<=n;++j)
			for(int k=0;k<=j;++k)
			{
				if(X^i)upd(f[i1][j][k],f[i0][j][k]),upd(f[i1][j][k+1],f[i0][j][k]);
				upd(f[i1][j+1][k],f[i0][j][k]),upd(f[i1][j+1][k+1],f[i0][j][k]);
			}
	}
	for(int i=1;i<=n;++i)f[i0][n][n]=((long long)f[i0][n][n]*i)%mod;
	return 0&printf("%d",f[i0][n][n]);
}