#include<bits/stdc++.h>

typedef long long LL;

const int N=1000005;

int n,f[N],ans[N];
LL k;

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%lld",&n,&k);
	if (k<(LL)n*(n+1)/2) {puts("-1");return 0;}
	for (int i=1;i<=n;i++) f[i]=i;
	puts("");
	LL ret=k-(LL)n*(n+1)/2;
	for (int i=1;i<=n;i++)
	{
		int t=std::min((LL)n,(LL)i+ret);
		t=find(t);
		ret-=std::max(0,t-i);
		ans[i]=t;
		f[t]=t-1;
	}
	printf("%lld\n",k-ret);
	for (int i=1;i<=n;i++) printf("%d ",i);
	puts("");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}