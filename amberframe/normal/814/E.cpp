#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;

const int maxn = 55;
const int mod = 1e9+7;
const int inv2 = mod+1>>1;

int f[maxn][maxn][maxn],w[maxn];
int g[maxn][maxn],n,d[maxn],s[maxn];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("detour.in","r",stdin);
		freopen("detour.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++) w[i]=i*(i-1)*(LL)inv2%mod; 
	for (int i=1;i<=n;i++) s[i]=s[i-1]+(d[i]==3);
	
	f[0][0][0]=1;
	for (int k=0;k<=n;k++)
	for (int p=0;p<=n;p++)
	for (int i=0,j=p;i<=p;i++,j--)
	if (k) {
		if (i) f[i][j][k]=(f[i][j][k]+(LL)f[i-1][j][k-1]*i)%mod;
		if (j) f[i][j][k]=(f[i][j][k]+(LL)f[i+1][j-1][k-1]*j)%mod;
	}
	else if (i) {
		if (i>1) f[i][j][k]=(f[i][j][k]+(LL)f[i-2][j][0]*(i-1))%mod;
		if (j>0) f[i][j][k]=(f[i][j][k]+(LL)f[i][j-1][0]*j)%mod;
	}
	else if (j) {
		if (j>2) f[i][j][k]=(f[i][j][k]+(LL)f[2][j-3][0]*w[j-1])%mod;
	}
	
	g[1][1+d[1]]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<i;j++)
	for (int k=1;k<j;k++)
		g[j][i]=(g[j][i]+(LL)g[k][j]*f[j-k-(s[j]-s[k])][s[j]-s[k]][i-j])%mod;
		
	int ans=0;
	for (int j=1;j<n;j++)
		ans=(ans+(LL)g[j][n]*f[n-j-(s[n]-s[j])][s[n]-s[j]][0])%mod;
	printf("%d",ans);
	return 0;
}