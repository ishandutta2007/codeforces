#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int t,n,a[200005];
inline int calc(int x)
{
	int p=1;
	while (p<x)
		p<<=1;
	return p-x;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		set<int> s;
		s.insert(0);
		for (int i=1;i<=n;++i)
			if (i==n||a[i]!=a[i+1])
				s.insert(i);
		int ans=inf;
		for (auto x:s)
		{
			int d=1,tmp=calc(x);
			while (x+d/2<n)
			{
				int y=*--s.upper_bound(x+d);
				ans=min(ans,tmp+d-(y-x)+calc(n-y));
				d*=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}