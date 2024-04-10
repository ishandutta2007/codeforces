#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;
const int MOD=1e9+7;

int n, mm, k, rem, sz=0, comp=0, ans=0;
int a[N], u[N], v[N], vis[N];
vector<int> g[N];
map<int, vector<pair<int, int> > > m;

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

void dfs(int v)
{
	if(vis[v])
		return;
	vis[v]=1;
	sz++;
	for(auto &it:g[v])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>mm>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=mm;i++)	
	{
		cin>>u[i]>>v[i];
		int x=a[u[i]]^a[v[i]];
		m[x].push_back({u[i], v[i]});
	}
	rem=(1LL<<k) - m.size();
	rem%=MOD;
	rem*=pow(2LL, n, MOD);
	rem%=MOD;
	ans+=rem;
	ans%=MOD;
	for(auto &it:m)
	{
		for(auto &j:it.second)
		{
			vis[j.first]=0;
			vis[j.second]=0;
			g[j.first].clear();
			g[j.second].clear();
		}
		for(auto &j:it.second)
		{
			g[j.first].push_back(j.second);
			g[j.second].push_back(j.first);
		}
		sz=0, comp=0;
		for(auto &j:it.second)
		{
			if(vis[j.first])
				continue;
			comp++;
			dfs(j.first);
		}
		int current=pow(2LL, n-sz+comp, MOD);
		ans+=current;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}