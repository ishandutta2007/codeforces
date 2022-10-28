#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;
const int MOD=998244353;

int n, m;
int odd=0, even=0;
bool check;
int col[N], vis[N];
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

void dfs(int k, int color)
{
	if(vis[k])
	{
		if(col[k]!=color)
			check=0;
		return;
	}	
	vis[k]=1;
	col[k]=color;
	odd+=color;
	even+=(color^1);
	for(auto &it:g[k])
		dfs(it, color^1);
}

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		check=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			g[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			odd=0, even=0;
			dfs(i, 0);
			int curways=pow(2LL, odd, MOD) + pow(2LL, even, MOD);
			curways%=MOD;
			ans*=curways;
			ans%=MOD;
		}
		if(!check)
			cout<<"0"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}