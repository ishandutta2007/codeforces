#include <iostream>
#include <vector>
using namespace std;
vector<int> v[300005],ans;
vector<pair<int,int> > e;
bool match[300005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=3*n;i++)
		{
			match[i]=0;
			v[i].clear();
		}
		e.clear();
		ans.clear();
		for (int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(i);
			v[b].push_back(i);
			e.push_back({a,b});
		}
		for (int i=1;i<=3*n;i++)
		{
			if (match[i])
			continue;
			for (int j:v[i])
			{
				int u=(i^e[j].first^e[j].second);
				if (!match[u])
				{
					match[i]=1;
					match[u]=1;
					ans.push_back(j+1);
					break;
				}
			}
		}
		if (ans.size()>=n)
		{
			printf("Matching\n");
			for (int i=0;i<n;i++)
			printf("%d ",ans[i]);
			printf("\n");
		}
		else
		{
			printf("IndSet\n");
			int cnt=0;
			for (int i=1;cnt!=n;i++)
			{
				if (!match[i])
				{
					printf("%d ",i);
					cnt++;
				}
			}
			printf("\n");
		}
	}
}