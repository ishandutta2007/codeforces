#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;  

int n;
int store[N];
set<int> have;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		if(v!=n)
		{
			cout<<"NO";
			return 0;
		}
		store[u]++;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(store[i]>have.size()+1)
		{
			cout<<"NO";
			return 0;
		}
		if(!store[i])
		{
			have.insert(i);
			continue;
		}
		int reqd=store[i]-1;
		int cur=n;
		while(reqd--)
		{
			g[cur].push_back(*have.begin());
			cur=*have.begin();
			have.erase(have.begin());
		}
		g[cur].push_back(i);
	}
	if(have.size())
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(auto it:g[i])
				cout<<i<<" "<<it<<endl;
		}
	}
	return 0;
}