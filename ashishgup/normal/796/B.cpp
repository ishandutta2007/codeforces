#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m, k, cur;
set<int> s;

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>cur;
		s.insert(cur);
	}
	cur=1;
	for(int i=1;i<=k;i++)
	{
		int u, v;
		cin>>u>>v;
		if(s.find(cur)!=s.end())
			break;
		if(cur==u)
			cur=v;
		else if(cur==v)
			cur=u;
	}
	cout<<cur;
	return 0;
}