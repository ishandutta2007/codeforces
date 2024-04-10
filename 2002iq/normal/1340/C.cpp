#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
int n,m,g,r,a[10005];
bool vis[11111111];
int cn(int i,int j)
{
	return i*(g+1)+j;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	sort(a,a+m);
	scanf("%d%d",&g,&r);
	deque<pair<int,int> > s;
	s.push_back({0,0});
	int ans=1e9;
	vector<pair<int,int> > v;
	while (!s.empty())
	{
		auto node=s.front();
		s.pop_front();
		if (vis[node.second])
		continue;
		vis[node.second]=1;
		int i=node.second/(g+1),j=node.second%(g+1);
		if (i==m-1)
		ans=min(ans,node.first*(g+r)+j);
		v.clear();
		if (i && j+a[i]-a[i-1]<=g)
		v.push_back({cn(i-1,j+a[i]-a[i-1]),0});
		if (i!=m-1 && j+a[i+1]-a[i]<=g)
		v.push_back({cn(i+1,j+a[i+1]-a[i]),0});
		if (j==g)
		v.push_back({cn(i,0),1});
		for (auto u:v)
		{
			if (u.second)
			s.push_back({node.first+u.second,u.first});
			else
			s.push_front({node.first+u.second,u.first});
		}
	}
	if (ans==1e9)
	ans=-1;
	printf("%d",ans);
}