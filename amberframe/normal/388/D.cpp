#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;

LL f[40][40][2];int num[40],k;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("sets.in","r",stdin);
		freopen("sets.out","w",stdout);
	#endif
	scanf("%d",&k);++k;
	for (int i=0;i<=29;i++,k>>=1) num[i]=k&1;
	f[30][0][0]=1;
	for (int i=29;i>=0;i--)
	for (int j=0;j<=30;j++)
	for (int k=0;k<=1;k++)
	if (LL v=f[i+1][j][k])
	{ 
		int nk0=k||num[i];
		if (k||num[i])
			(f[i][j+1][k]+=v)%=mod;
		if (!j)
			(f[i][j][nk0]+=v)%=mod;
		else {
			(f[i][j][nk0]+=v<<j-1)%=mod;
			if (k||num[i])
				(f[i][j][k]+=v<<j-1)%=mod;
		}
	}
	LL sum=0;
	for (int j=0;j<=30;j++)
		(sum+=f[0][j][1])%=mod;
	printf("%lld",sum);
	return 0;
}