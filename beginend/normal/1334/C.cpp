#include<bits/stdc++.h>

typedef long long LL;

const int N=300005;

int n;
LL a[N],b[N],val[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
		for (int i=2;i<=n;i++) val[i]=std::max((LL)0,a[i]-b[i-1]);
		val[1]=std::max((LL)0,a[1]-b[n]);
		LL s=0;
		for (int i=1;i<=n;i++) s+=val[i];
		LL ans=a[1]+s-val[1];
		for (int i=2;i<=n;i++) ans=std::min(ans,a[i]+s-val[i]);
		printf("%lld\n",ans);
	}
	return 0;
}