#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;
#define pb push_back
const int maxn = 2005;
const int N = 2000;
const int mod = (1<<30)-1;

int a,b,c,ans;
int prm[maxn],tot,miu[maxn];
int f[maxn][maxn],is[maxn];
int gcd(int u,int v) {
	return v?gcd(v,u%v):u;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	#endif
	miu[1]=1;
	scanf("%d %d %d",&a,&b,&c);
	for (int i=2;i<=N;i++) {
		if (!is[i]) {prm[++tot]=i;miu[i]=-1;}
		for (int j=1;j<=tot&&prm[j]*i<=N;++j) {
			int t=prm[j]*i;is[t]=1;
			if (i%prm[j]) miu[t]=-miu[i];
			else {miu[t]=0;break;}
		}
	}
	for (int i=1;i<=N;i++)
	for (int k=1;k<=N;k++)
	if (gcd(i,k)==1)
		for (int j=k;j<=N;j+=k) f[i][j]++;
	for (int i=1;i<=N;i++)
	for (int j=1;j<=N;j++)
		f[i][j]+=f[i][j-1];
	for (int g=1;g<=N;g++)
	for (int i=1;i<=a;i++)
		ans+=miu[g]*(gcd(i,g)==1)*f[i][b/g]*f[i][c/g]*(a/i);
	ans&=mod;ans+=mod+1;ans&=mod;
	printf("%d\n",ans);
	return 0;
}