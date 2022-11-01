#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=5005;
const int MOD=1000000007;

int n,k,f[N][N];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	f[1][1]=n;
	for (int i=2;i<=k;i++)
		for (int j=1;j<=min(n,i);j++)
			f[i][j]=((LL)f[i-1][j]*j+(LL)f[i-1][j-1]*(n-j+1))%MOD;
	int ans=0;
	for (int i=1;i<=min(n,k);i++) (ans+=(LL)f[k][i]*ksm(2,n-i)%MOD)%=MOD;
	printf("%d",ans);
	return 0;
}