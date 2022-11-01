#include<bits/stdc++.h>

typedef long long LL;

const int N=100005;
const LL inf=(LL)1e15;

int n,a[N],tot;

LL solve(int p)
{
	LL ans=0;
	for (int i=1;i<=tot;i+=p)
	{
		int pos=a[(i+i+p-1)/2];
		for (int j=1;j<=p;j++) ans+=abs(pos-a[i+j-1]);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (x) a[++tot]=i;
	}
	LL ans=inf;
	for (int i=2;i<=tot;i++)
		if (tot%i==0) ans=std::min(ans,solve(i));
	if (ans==inf) ans=-1;
	printf("%lld\n",ans);
	return 0;
}