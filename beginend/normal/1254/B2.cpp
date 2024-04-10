#include<bits/stdc++.h>

typedef long long LL;

const int N=1000005;
const LL inf=(LL)1e18;

int n,tot;
LL a[N],b[N];

LL solve(LL p)
{
	for (int i=1;i<=n;i++) b[i]=a[i];
	LL ans=0,sum=0;
	int l=1;
	while (l<=n)
	{
		b[l]%=p;
		if (!b[l]) {l++;continue;}
		LL ret=b[l];
		int r=l,mid=l;
		while (ret<p)
		{
			ret+=b[++r];
			if (ret-b[r]<=p/2&&ret>p/2) mid=r;
		}
		ret-=a[r];
		for (int i=l;i<r;i++) ans+=(LL)abs(i-mid)*b[i],b[i]=0;
		ans+=(LL)(p-ret)*(r-mid);
		b[r]-=p-ret;
		l=r;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	LL cnt=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),cnt+=a[i];
	LL ans=inf;
	for (int i=2;(LL)i*i<=cnt;i++)
		if (cnt%i==0)
		{
			ans=std::min(ans,solve(i));
			while (cnt%i==0) cnt/=i;
		}
	if (cnt>1) ans=std::min(ans,solve(cnt));
	if (ans==inf) ans=-1;
	printf("%lld\n",ans);
	return 0;
}