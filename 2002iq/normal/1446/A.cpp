#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		long long w;
		scanf("%d%I64d",&n,&w);
		vector<pair<int,int> > v;
		for (int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			v.push_back({a,i});
		}
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		long long cur=0;
		vector<int> ans;
		for (auto p:v)
		{
			if (cur+p.first<=w)
			{
				cur+=p.first;
				ans.push_back(p.second);
			}
		}
		if (cur<(w+1)/2)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans.size());
		for (int i:ans)
		printf("%d ",i);
		printf("\n");
	}
}