#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=1e9+7;

int n;
int a[N], vis[N], mark[N], checkcycle[N];
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
	if(mark[k])
		return;
	mark[k]=1;
	for(auto it:g[k])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	int chain=n;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int cur=i, ctr=0;
		if(mark[cur])
			continue;
		while(!vis[cur])
		{
			vis[cur]=1;
			cur=a[cur];
		}
		while(!checkcycle[cur])
		{
			checkcycle[cur]=1;
			ctr++;
			dfs(cur);
			cur=a[cur];
		}
		if(ctr>1)
		{
			chain-=ctr;
			ans*=((pow(2LL, ctr, MOD) - 2 + MOD));
			ans%=MOD;
		}
	}
	ans*=pow(2LL, chain, MOD);
	ans%=MOD;
	cout<<ans;
	return 0;
}