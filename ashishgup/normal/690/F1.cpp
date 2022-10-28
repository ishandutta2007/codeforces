#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k1=2, ans=0;
int dist[N][5];
vector<int> g[N];

void dfs(int k, int par)
{
	dist[k][0]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		for(int i=0;i<k1;i++)
		{
			ans+=dist[k][i]*dist[it][k1-i-1];
		}
		for(int i=0;i<=k1;i++)
		{
			dist[k][i+1]+=dist[it][i];
		}
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
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, 0);
    cout<<ans;
    return 0;
}