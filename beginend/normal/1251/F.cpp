#include<bits/stdc++.h>

typedef long long LL;

const int N=300005;
const int MOD=998244353;

int n,k,jc[N],ny[N],a[N*4],b[N*4],rev[N*4],L,ans[N*2],m,q,cnt[N];

void pre(int n)
{
	int lg=0;
	for (L=1;L<=n;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
}

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

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
	for (int i=0;i<L;i++) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i=1;i<L;i<<=1)
	{
		int wn=ksm(3,f==1?(MOD-1)/i/2:MOD-1-(MOD-1)/i/2);
		for (int j=0;j<L;j+=(i<<1))
		{
			int w=1;
			for (int k=0;k<i;k++)
			{
				int u=a[j+k],v=(LL)a[j+k+i]*w%MOD;
				a[j+k]=(u+v)%MOD;a[j+k+i]=(u+MOD-v)%MOD;
				w=(LL)w*wn%MOD;
			}
		}
	}
	if (f==-1) for (int i=0,inv=ksm(L,MOD-2);i<L;i++) a[i]=(LL)a[i]*inv%MOD;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),m=std::max(m,x),cnt[x]++;
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	pre(n*2);
	while (k--)
	{
		int h;scanf("%d",&h);
		int s1=0,s2=0;
		for (int i=1;i<h;i++)
			if (cnt[i]==1) s2++;
			else if (cnt[i]>=2) s1+=2;
		for (int i=0;i<L;i++) a[i]=b[i]=0;
		for (int i=0;i<=s1;i++) a[i]=C(s1,i);
		for (int i=0;i<=s2;i++) b[i]=(LL)ksm(2,i)*C(s2,i)%MOD;
		NTT(a,1);NTT(b,1);
		for (int i=0;i<L;i++) a[i]=(LL)a[i]*b[i]%MOD;
		NTT(a,-1);
		for (int i=0;i<=s1+s2;i++) (ans[h+i+1]+=a[i])%=MOD;
	}
	scanf("%d",&q);
	while (q--)
	{
		int x;scanf("%d",&x);
		printf("%d\n",ans[x/2]);
	}
	return 0;
}