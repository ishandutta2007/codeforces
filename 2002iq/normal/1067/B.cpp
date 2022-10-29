#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
bool del[100005];
pair<int,int> far(int node,int p)
{
	pair<int,int> ans(0,node);
	for (int u:v[node])
	{
		if (!del[u] && u!=p)
		{
			auto tmp=far(u,node);
			tmp.first++;
			ans=max(ans,tmp);
		}
	}
	return ans;
}
vector<int> path;
bool find(int node,int p,int t)
{
	if (node==t)
	return 1;
	for (int u:v[node])
	{
		if (!del[u] && u!=p && find(u,node,t))
		{
			path.push_back(u);
			return 1;
		}
	}
	return 0;
}
int center(int node)
{
	auto f=far(node,0),s=far(f.second,0);
	path.clear();
	find(f.second,0,s.second);
	path.push_back(f.second);
	return path[path.size()/2];
}
bool dfs(int node,int k)
{
	if (!k)
	return (v[node].size()==1);
	int c=center(node);
	if (far(c,0).first!=k)
	return 0;
	del[c]=1;
	bool ans=1;
	int cnt=0;
	for (int u:v[c])
	{
		if (!del[u])
		{
			ans&=dfs(u,k-1);
			cnt++;
		}
	}
	return (ans && cnt>=3);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if (dfs(1,k))
	printf("YES\n");
	else
	printf("NO\n");
}