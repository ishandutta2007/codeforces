#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=20;
const int M=140005;
const int MOD=1000000007;
const int ny2=(MOD+1)/2;

int n,m,bin[N],fib[M],f[N][M],a[M],b[M],c[M],cnt[M];

void solve1()
{
	for (int i=0;i<bin[n];i++) f[cnt[i]][i]+=a[i];
	for (int i=0;i<=n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<bin[n];k++)
				if (k&bin[j]) (f[i][k]+=f[i][k^bin[j]])%=MOD;
	for (int i=n;i>=0;i--)
		for (int j=0;j<bin[n];j++)
		{
			int w=0;
			for (int k=0;k<=i;k++) (w+=(LL)f[k][j]*f[i-k][j]%MOD)%=MOD;
			f[i][j]=w;
		}
	for (int i=0;i<=n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<bin[n];k++)
				if (k&bin[j]) (f[i][k]+=MOD-f[i][k^bin[j]])%=MOD;
	for (int i=0;i<bin[n];i++) a[i]=(LL)f[cnt[i]][i]*fib[i]%MOD;
}

void solve2()
{
	for (int i=0;i<bin[n];i++) b[i]=(LL)b[i]*fib[i]%MOD;
}

void FWT(int *a,int l,int r,int c)
{
	if (l==r) return;
	int mid=(l+r)/2,L=r-mid;
	FWT(a,l,mid,c);FWT(a,mid+1,r,c);
	for (int i=l;i<=mid;i++)
	{
		int u=a[i],v=a[i+L];
		if (c==1) a[i]=(u+v)%MOD,a[i+L]=(u+MOD-v)%MOD;
		else a[i]=(LL)(u+v)*ny2%MOD,a[i+L]=(LL)(u+MOD-v)*ny2%MOD;
	}
}

void solve3()
{
	FWT(c,0,bin[n]-1,1);
	for (int i=0;i<bin[n];i++) c[i]=(LL)c[i]*c[i]%MOD;
	FWT(c,0,bin[n]-1,-1);
	for (int i=0;i<bin[n];i++) c[i]=(LL)c[i]*fib[i]%MOD;
}

void FMT(int *f,int c)
{
	for (int i=0;i<n;i++)
		for (int j=bin[n]-1;j>=0;j--)
			if (!(j&bin[i])) (f[j]+=c*f[j^bin[i]])%=MOD;
}

void solve4()
{
	FMT(a,1);FMT(b,1);FMT(c,1);
	for (int i=0;i<bin[n];i++) a[i]=(LL)a[i]*b[i]%MOD*c[i]%MOD;
	FMT(a,-1);
	int ans=0;
	for (int i=0;i<n;i++) (ans+=a[bin[i]])%=MOD;
	printf("%d",(ans+MOD)%MOD);
}

int main()
{
	n=17;scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		a[x]++;b[x]++;c[x]++;
	}
	bin[0]=fib[1]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<bin[n];i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int i=2;i<bin[n];i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	solve1();
	solve2();
	solve3();
	solve4();
	return 0;
}