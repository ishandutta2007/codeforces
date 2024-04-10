#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=505;
const int MOD=998244353;

int n,m,mn[N][N],f[N][N],a[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mn[i][i]=i;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			mn[i][j]=a[mn[i][j-1]]<a[mn[i+1][j]]?mn[i][j-1]:mn[i+1][j];
		}
	for (int i=1;i<=n+1;i++) f[i][i]=f[i][i-1]=1;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l,pos=mn[i][j],s1=0,s2=0;
			for (int k=i;k<=pos;k++) (s1+=(LL)f[i][k-1]*f[k][pos-1]%MOD)%=MOD;
			for (int k=pos;k<=j;k++) (s2+=(LL)f[pos+1][k]*f[k+1][j]%MOD)%=MOD;
			(f[i][j]+=(LL)s1*s2%MOD)%=MOD;
		}
	printf("%d\n",f[1][n]);
	return 0;
}