#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 800005;
const int mod = 998244353;

int inc(int u,int v) {u+=v;return u%mod;}
int dec(int u,int v) {u-=v;return u%mod;}
LL fpm(LL p,LL k) {
	LL res=1ll;
	while (k<0) k+=mod-1;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}
int rv[maxn];
void ntt(int *f,int len,int idft)
{
	for (int i=1;i<len;i++)
		rv[i]=rv[i>>1]>>1|(i&1?len>>1:0);
	for (int i=1;i<len;i++)
		if (i<rv[i]) swap(f[i],f[rv[i]]);
	for (int p=2;p<=len;p<<=1)
	{
		LL wn=fpm(3,(mod-1)/p*idft);
		for (int i=0;i<len;i+=p)
		{
			LL w=1ll;
			for (int j=i;j<i+p/2;j++)
			{
				int u=f[j],v=f[j+p/2]*w%mod;w=w*wn%mod;
				f[j]=inc(u,v);f[j+p/2]=dec(u,v);
			}
		}
	}
	if (idft==1) return ;
	LL inc=fpm(len,-1);
	for (int i=0;i<len;i++)
		f[i]=f[i]*inc%mod;
}

int tmp[maxn];
void GetInv(int *A,int *B,int t)
{
	if (t==1) {B[0]=fpm(A[0],-1);return ;}
	GetInv(A,B,t>>1);
	memcpy(tmp,A,t<<2);memset(tmp+t,0,t<<2);
	ntt(tmp,t<<1,1);ntt(B,t<<1,1);
	for (int i=0;i<t<<1;i++) B[i]=B[i]*(2ll-(LL)tmp[i]*B[i]%mod)%mod;
	ntt(B,t<<1,-1);memset(B+t,0,t<<2);
}
int a[maxn],b[maxn];
void conval(int *A,int *B,int *C,int t)
{
	memcpy(a,A,t<<2);ntt(a,t,1);
	memcpy(b,B,t<<2);ntt(b,t,1);
	for (int i=0;i<t;i++) C[i]=(LL)a[i]*b[i]%mod;
	ntt(C,t,-1);
}
int invB[maxn];
void GetSqrt(int *A,int *B,int t)
{
	if (t==1) {B[0]=1;return ;}
	GetSqrt(A,B,t>>1);
	memset(invB,0,t<<3);GetInv(B,invB,t);
	memcpy(tmp,A,t<<2);memset(tmp+t,0,t<<2);
	conval(tmp,invB,tmp,t<<1);
	LL inc=fpm(2,-1);
	for (int i=t>>1;i<t;i++) B[i]=inc*tmp[i]%mod;
}

int c[maxn],sc[maxn],ic[maxn],n,m;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int o,i=1;i<=n;i++)
		scanf("%d",&o),c[o]++;
	int k=1;while (k<=m) k<<=1;
	c[0]=1;
	for (int i=1;i<k;i++)
		c[i]=-4ll*c[i]%mod;
	GetSqrt(c,sc,k);sc[0]++;
	GetInv(sc,ic,k);
	for (int i=1;i<=m;i++)
	{
		int ans=ic[i]*2ll%mod;
		printf("%d\n",ans<0?ans+mod:ans);
	}
	return 0;
}