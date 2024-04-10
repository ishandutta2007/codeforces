#include <bits/stdc++.h>
using namespace std;
int no[300005];
bool ex[300005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			no[i]=1e9;
			ex[i]=0;
		}
		set<int> s;
		for (int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			s.insert(a);
			if (s.upper_bound(a)!=s.end())
			no[a]=min(no[a],*s.upper_bound(a));
			ex[a]=1;
		}
		int cur=n,ans=n;
		for (int i=n;i>0;i--)
		{
			if (s.find(i)!=s.end())
			s.erase(i);
			while (cur>=no[i])
			{
				if (ex[cur])
				s.insert(cur);
				cur--;
			}
			ans=min(ans,(int)s.size());
		}
		printf("%d\n",ans);
	}
}