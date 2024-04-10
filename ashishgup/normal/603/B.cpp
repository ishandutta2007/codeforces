#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int p, k, ans;
int vis[N];
vector<int> g[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	for(auto it:g[k])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>p>>k;
	if(k==0)
		ans=pow(p, p-1, MOD);
	else if(k==1)
		ans=pow(p, p, MOD);
	else
	{
		for(int i=0;i<=p-1;i++)
		{
			int u=i;
			int v=(k*i)%p;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int components=0;
		for(int i=1;i<=p-1;i++)
		{
			if(!vis[i])
			{
				components++;
				dfs(i);
			}
		}
		ans=pow(p, components, MOD);
	}
	cout<<ans;
	return 0;
}