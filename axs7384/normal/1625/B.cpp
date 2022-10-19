#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=300005;
int t,n;
pair<int,int> a[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a+1,a+1+n);
		int len=inf;
		for (int i=1;i<n;++i)
			if (a[i].first==a[i+1].first)
				len=min(len,a[i+1].second-a[i].second);
		printf("%d\n",len==inf?-1:n-len);
	}
	return 0;
}