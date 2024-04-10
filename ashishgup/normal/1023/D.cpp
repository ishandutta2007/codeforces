#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, q, reqd=1;
int a[N];
set<int> g[N];
set<int> active;

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		active.insert(i);
		g[a[i]].insert(i);
	}
	if(!g[q].size() && !g[0].size())
	{
		cout<<"NO";
		return 0;
	}
	if(!g[q].size())
	{
		a[*g[0].begin()]=q;
		active.erase(*g[0].begin());
		g[0].erase(g[0].begin());
	}	
	for(int i=1;i<=q;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			a[i]=a[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
			a[i]=a[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		g[a[i]].insert(i);
	}
	for(int i=q;i>=1;i--)
	{
		if(!g[i].size())
			continue;
		auto idx=*(g[i].begin());
		auto it=active.lower_bound(idx);
		vector<int> v;
		while(it!=active.end() && g[i].find(*it)!=g[i].end())
		{	
			v.push_back(*it);
			it++;
		}	
		for(auto it:v)
			active.erase(it);
		if(!active.size())
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
			return 0;
		}
	}
	for(auto &it:g[0])
		active.erase(it);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			a[i]=a[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
			a[i]=a[i+1];
	}
	if(!active.size())
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		return 0;
	}
	cout<<"NO";
	return 0;
}