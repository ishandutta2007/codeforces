#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,vis[N];
pair<int,int> a[N];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	return (x.second-x.first)<(y.second-y.first);
}
inline int work(int l,int r)
{
	for (int i=l;i<=r;++i)
		if (!vis[i])
		{
			vis[i]=1;
			return i;
		}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d%d",&a[i].first,&a[i].second);
		for (int i=1;i<=n;++i)
			vis[i]=0;
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;++i)
			printf("%d %d %d\n",a[i].first,a[i].second,work(a[i].first,a[i].second));
	}
	return 0;
}