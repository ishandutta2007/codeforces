#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int flip[N];
vector<pair<int, int> > g[N];

void dfs(int k, int par, int store)
{
	flip[k]=store;
	for(auto &it:g[k])
	{
		if(it.first==par)
			continue;
		ans+=it.second;
		int val=(it.second==0)?1:-1;
		dfs(it.first, k, store+val);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, 0});
		g[v].push_back({u, 1});
	}
	dfs(1, 1, 0);
	int finans=ans;
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		int cur=ans+flip[i];
		if(cur<finans)
		{
			finans=cur;
			v.clear();
			v.push_back(i);
		}
		else if(cur==finans)
			v.push_back(i);
	}
	cout<<finans<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}