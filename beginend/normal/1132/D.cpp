#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=200005;

int n,m;
LL a[N],b[N],c[N];
std::vector<int> vec[N];

bool check(LL mid)
{
	for (int i=1;i<=m;i++) vec[i].clear();
	for (int i=1;i<=n;i++)
		if (a[i]/b[i]<m) vec[a[i]/b[i]+1].pb(i),c[i]=a[i]%b[i];
	int p=1;
	for (int i=1;i<=m;i++)
	{
		while (p<=m&&!vec[p].size()) p++;
		if (p>m) return 1;
		int x=vec[p].back();vec[p].pop_back();
		if (p<i||p==i&&c[x]+mid<b[x]) return 0;
		c[x]=c[x]+mid;
		LL ret=c[x]/b[x];
		if (p+ret<=m) vec[p+ret].pb(x),c[x]%=b[x];
	}
	while (p<=m&&!vec[p].size()) p++;
	return p>m?1:0;
}

int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	LL l=0,r=(LL)2e12;
	while (l<=r)
	{
		LL mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r<(LL)2e12?r+1:-1);
	return 0;
}