#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n;
int a[N];
map<int, vector<int> > m;
vector<int> g[N];

int32_t main()
{
	IOS;
	m[-1e9-1];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]].push_back(i);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto it=--m.end();
	int maxval=it->first;
	int maxnode=it->second[0];
	int maxsize=it->second.size();
	if(maxsize==1)
	{
		int ct=0;
		--it;
		int secondmax=it->first;
		for(auto u:g[maxnode])
		{
			if(a[u]==secondmax)
				ct++;
		}
		if(ct==it->second.size()||secondmax<maxval-1)
			cout<<maxval<<endl;
		else
			cout<<maxval+1<<endl;
	}
	else
	{
		bool check=0;
		for(int i=1;i<=n;i++)
		{
			int ct=0;
			if(a[i]==maxval)
				ct++;
			for(auto u:g[i])
				if(a[u]==maxval)
					ct++;
			if(ct==maxsize)
			{
				check=1;
				break;
			}
		}
		if(check)
			cout<<maxval+1<<endl;
		else
			cout<<maxval+2<<endl;
	}
	return 0;
}