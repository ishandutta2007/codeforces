#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=(1<<16);

int n, edges=0;
int deg[N], val[N];
set<pair<int, int> > s;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>deg[i]>>val[i];
		s.insert({deg[i], i});
	}
	while(s.size())
	{
		pair<int, int> cur=*s.begin();
		s.erase(cur);
		if(cur.first==0)
			continue;
		edges++;
		int parent=val[cur.second];
		val[parent]^=cur.second;
		s.erase({deg[parent], parent});
		deg[parent]--;
		s.insert({deg[parent], parent});
		g[cur.second].push_back(parent);
		g[parent].push_back(cur.second);
	}
	cout<<edges<<endl;
	for(int i=0;i<n;i++)
	{
		for(auto &it:g[i])
		{
			if(it>i)
				cout<<i<<" "<<it<<endl;
		}
	}
	return 0;	
}