#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

LL n,m,k,a[N];

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
	int ans=0;
	for (LL l=1;l<=m;l++)
	{
		LL r=l;
		while (r<m&&(a[l]-1-(l-1))/k==(a[r+1]-1-(l-1))/k) r++;
		ans++;
		l=r;
	}
	printf("%d\n",ans);
	return 0;
}