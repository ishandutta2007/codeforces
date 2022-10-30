#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 200005;
const LL mod = 1e9+7;
const int maxk = 2005;
const int N = 200000;

LL fac[maxn],inc[maxn];
LL QuickPow(LL p,LL k) {
	LL res=1ll;p%=mod;
	for (;k;k>>=1,(p*=p)%=mod)
		if (k&1) (res*=p)%=mod;
	return res;
}
struct node{int r,c;}p[maxn];
LL paths(int i,int j) {
	int dx=p[j].r-p[i].r,dy=p[j].c-p[i].c;
	return fac[dx+dy]*inc[dx]%mod*inc[dy]%mod;
}
bool comp(node a,node b) {
	return a.r!=b.r?a.r<b.r:a.c<b.c;
}
bool check(int i,int j) {
	return p[i].r<=p[j].r&&p[i].c<=p[j].c;
}

int n,m,t,K,s;
LL f[maxk][20];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("rover.in","r",stdin);
		freopen("rover.out","w",stdout);
	#endif
	fac[0]=inc[0]=1ll;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
	inc[N]=QuickPow(fac[N],mod-2);
	for (int i=N;i>=2;i--) inc[i-1]=inc[i]*i%mod;
	
	scanf("%d %d %d %d",&n,&m,&t,&s);
	for (int r,c,i=1;i<=t;i++) {
		scanf("%d %d",&r,&c);
		if (r==1&&c==1) {s=(s+1)/2;continue;}
		if (r==n&&c==m) {s=(s+1)/2;continue;}
		p[++K]=(node){r,c};
	}
	p[0]=(node){1,1};p[++K]=(node){n,m};
	sort(p+1,p+K+1,comp);
	
	f[0][0]=1ll;
	for (int i=1;i<=K;i++)
	for (int j=0;j<20;j++) {
		f[i][j]=paths(0,i);
		for (int k=0;k<j;k++)
			(f[i][j]-=f[i][k])%=mod;
		for (int k=1;k<i;k++)
			if (check(k,i)) (f[i][j]-=f[k][j]*paths(k,i))%=mod;
	}
	LL ans=0,sum=paths(0,K);
	for (int j=0;j<20;j++,s=(s+1)/2) {
		(sum-=f[K][j])%=mod;
		(ans+=f[K][j]*s)%=mod;
	}
	(ans+=sum)%=mod;
	(ans*=QuickPow(paths(0,K),mod-2))%=mod;
	if (ans<0) ans+=mod;
	printf("%lld",ans);
	return 0;
}