#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;
const LL inf=(LL)1e17;

int n,m;
LL k,a[N],mn[15];

int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	k=-k;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for (int i=1;i<m;i++) mn[i]=inf;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int w=i/m;
		for (int j=0;j<i%m;j++) ans=std::max(ans,(LL)(w+1)*k+a[i]-mn[j]);
		for (int j=i%m;j<m;j++) ans=std::max(ans,(LL)w*k+a[i]-mn[j]);
		mn[i%m]=std::min(mn[i%m],(LL)w*k+a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}