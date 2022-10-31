#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;
const int MOD=998244353;

int n,k,a[N];

int main()
{
	n=1;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	LL sum=0;int ans=1,ls=0;
	for (int i=1;i<=n;i++)
		if (a[i]>n-k)
		{
			if (ls) ans=(LL)ans*(i-ls)%MOD;
			sum+=(LL)a[i];
			ls=i;
		}
	printf("%lld %d\n",sum,ans);
	return 0;
}