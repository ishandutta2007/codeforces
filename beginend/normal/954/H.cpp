#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=5001;
const int MOD=1000000007;

int n,a[N],f[N][N*2],pre[N],ans[N*2];

int main()
{
	scanf("%d",&n);pre[0]=1;
	for (int i=1;i<n;i++) scanf("%d",&a[i]),pre[i]=(LL)pre[i-1]*a[i]%MOD;
	for (int i=n;i>=1;i--)
	{
		f[i][0]=1;
		for (int j=1;j<=n-i;j++)
		{
			f[i][j]=(LL)f[i+1][j-1]*a[i]%MOD;
			(ans[j]+=(LL)f[i][j]*pre[i-1]%MOD)%=MOD;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=n*2-2;j>=1;j--)
		{
			f[i][j]=f[i-1][j-1];
			if (i>1&&j>1&&j-2<n&&j<=i+n-2) (f[i][j]+=(LL)f[i][j-2]*(a[i-1]-1)%MOD)%=MOD;
			(ans[j]+=(LL)f[i][j]*pre[i-1]%MOD)%=MOD;
		}
	}
	for (int i=1;i<=n*2-2;i++) printf("%d ",(LL)(MOD+1)/2*ans[i]%MOD);
	return 0;
}