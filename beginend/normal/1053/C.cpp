#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;
const int inf=10;
const int MOD=1000000007;

int n,q,a[N],w[N];
LL c1[N],c2[N],c3[N],c4[N],c5[N],c6[N];

void ins1(int x,LL y)
{
	while (x<=n) c1[x]+=y,x+=x&(-x);
}

void ins2(int x,LL y)
{
	while (x<=n) (c2[x]+=y)%=MOD,x+=x&(-x);
}

void ins3(int x,LL y)
{
	while (x<=n) (c3[x]+=y)%=MOD,x+=x&(-x);
}

void ins4(int x,LL y)
{
	while (x<=n) c4[x]+=y,x+=x&(-x);
}

void ins5(int x,LL y)
{
	while (x<=n) (c5[x]+=y)%=MOD,x+=x&(-x);
}

void ins6(int x,LL y)
{
	while (x<=n) (c6[x]+=y)%=MOD,x+=x&(-x);
}

LL get1(int x)
{
	LL ans=0;
	while (x) ans+=c1[x],x-=x&(-x);
	return ans;
}

LL get2(int x)
{
	LL ans=0;
	while (x) (ans+=c2[x])%=MOD,x-=x&(-x);
	return ans;
}

LL get3(int x)
{
	LL ans=0;
	while (x) (ans+=c3[x])%=MOD,x-=x&(-x);
	return ans;
}

LL get4(int x)
{
	LL ans=0;
	while (x) ans+=c4[x],x-=x&(-x);
	return ans;
}

LL get5(int x)
{
	LL ans=0;
	while (x) (ans+=c5[x])%=MOD,x-=x&(-x);
	return ans;
}

LL get6(int x)
{
	LL ans=0;
	while (x) (ans+=c6[x])%=MOD,x-=x&(-x);
	return ans;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]),ins5(i,(LL)w[i]*i%MOD),ins6(i,(LL)w[i]*(n-i+1)%MOD);
	for (int i=1;i<=n;i++) ins1(i,a[i]),ins2(i,(LL)a[i]*w[i]%MOD),ins3(i,(LL)(inf-a[i])*w[i]%MOD),ins4(i,w[i]);
	while (q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (x<0)
		{
			x=-x;
			ins2(x,MOD-(LL)a[x]*w[x]%MOD);ins3(x,MOD-(LL)(inf-a[x])*w[x]%MOD);ins4(x,-w[x]);
			ins5(x,MOD-(LL)w[x]*x%MOD);ins6(x,MOD-(LL)w[x]*(n-x+1)%MOD);
			w[x]=y;
			ins2(x,(LL)a[x]*w[x]%MOD);ins3(x,(LL)(inf-a[x])*w[x]%MOD);ins4(x,w[x]);
			ins5(x,(LL)w[x]*x%MOD);ins6(x,(LL)w[x]*(n-x+1)%MOD);
		}
		else
		{
			int l=x,r=y;
			while (l<=r)
			{
				int mid=(l+r)/2;
				if (get4(mid)-get4(x-1)>=get4(y)-get4(mid)) r=mid-1;
				else l=mid+1;
			}
			int mid=r+1;
			LL ans=0;
			LL v1=get4(mid)-get4(x-1),v2=get4(y)-get4(mid);
			if (mid<y) (ans+=get2(y)-get2(mid)-(LL)v2%MOD*a[mid+1]%MOD-(get5(y)-get5(mid)-(LL)v2%MOD*(mid+1)%MOD))%=MOD;
			(ans+=get3(mid)-get3(x-1)-(LL)v1%MOD*(inf-a[mid])%MOD-(get6(mid)-get6(x-1)-(LL)v1%MOD*(n-mid+1)%MOD))%=MOD;
			if (mid<y) (ans+=(LL)std::min(v1,v2)%MOD*(a[mid+1]-a[mid]-1)%MOD)%=MOD;
			(ans+=MOD)%=MOD;
			printf("%lld\n",ans);
		}
	}
	return 0;
}