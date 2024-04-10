#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=400005;
const int MOD=998244353;

int n,m,a[N],F[N],G[N],rev[N],b[N],T,lg;

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

void NTT(int *a,int f)
{
	for (int i=0;i<T;i++) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i=1;i<T;i<<=1)
	{
		int wn=ksm(3,f==1?(MOD-1)/i/2:MOD-1-(MOD-1)/i/2);
		for (int j=0;j<T;j+=(i<<1))
		{
			int w=1;
			for (int k=0;k<i;k++)
			{
				int u=a[j+k],v=(LL)w*a[j+k+i]%MOD;
				a[j+k]=(u+v)%MOD;a[j+k+i]=(u+MOD-v)%MOD;
				w=(LL)w*wn%MOD;
			}
		}
	}
	if (f==-1)
	{
		int ny=ksm(T,MOD-2);
		for (int i=0;i<T;i++) a[i]=(LL)a[i]*ny%MOD;
	}
}

void get_inv(int *a,int n)
{
	if (n==1) {G[0]=ksm(a[0],MOD-2);return;}
	get_inv(a,n/2);
	for (T=1,lg=0;T<=n;T<<=1,lg++);
	for (int i=0;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1)),b[i]=0;
	for (int i=0;i<n;i++) b[i]=a[i];
	NTT(b,1);NTT(G,1);
	for (int i=0;i<T;i++) G[i]=(G[i]*2%MOD+MOD-(LL)G[i]*G[i]%MOD*b[i]%MOD)%MOD;
	NTT(G,-1);
	for (int i=n;i<T;i++) G[i]=0;
}

void get_sqrt(int *a,int n)
{
	if (n==1) {F[0]=1;return;}
	get_sqrt(a,n/2);
	get_inv(F,n);
	for (int i=0;i<n;i++) G[i]=(LL)G[i]*((MOD+1)/2)%MOD;
	for (T=1,lg=0;T<n;T<<=1,lg++);
	for (int i=0;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	NTT(F,1);
	for (int i=0;i<T;i++) F[i]=(LL)F[i]*F[i]%MOD;
	NTT(F,-1);
	for (int i=0;i<n;i++) (F[i]+=a[i])%=MOD;
	T<<=1;lg++;
	for (int i=0;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	NTT(F,1);NTT(G,1);
	for (int i=0;i<T;i++) F[i]=(LL)F[i]*G[i]%MOD,G[i]=0;
	NTT(F,-1);
	for (int i=n;i<T;i++) F[i]=0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (x<=m) a[x]++;
	}
	int k;
	for (k=1;k<=m;k<<=1);
	a[0]=1;
	for (int i=1;i<k;i++) a[i]=(MOD-(LL)a[i]*4%MOD)%MOD;
	get_sqrt(a,k);
	F[0]++;
	get_inv(F,k);
	for (int i=1;i<=m;i++) printf("%d\n",(LL)G[i]*2%MOD);
	return 0;
}