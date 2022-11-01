#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=200005;

int n;
std::priority_queue<int, std::vector<int>, std::greater<int> > que;
std::vector<int> vec[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int m,p;scanf("%d%d",&m,&p);
			vec[m].pb(p);
		}
		LL ans=0;
		for (int i=n-1;i>=0;i--)
		{
			for (int j:vec[i]) que.push(j);
			while (que.size()>n-i)
			{
				ans+=que.top();
				que.pop();
			}
			vec[i].clear();
		}
		printf("%lld\n",ans);
		while (!que.empty()) que.pop();
	}
	return 0;
}