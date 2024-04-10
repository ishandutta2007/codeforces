#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[1005],deg[1005],b[1005],n,m,dp[1005];
vector<int> e[1005],E[1005];
const int X=1500;
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]) return 0;
	return 1;
}
void cl()
{
	for(int i=1;i<=n;i++) a[i]=deg[i]=0,e[i].clear(),E[i].clear(),dp[i]=0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		cl();
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin >> u >> v;
			++deg[u];
			E[v].push_back(u);
			e[u].push_back(v);
		}
		if(check())
		{
			cout << "0\n";
			continue; 
		}
		int flag=0;
		for(int i=1;i<=X;i++)
		{
			for(int i=1;i<=n;i++) b[i]=a[i];
			for(int i=1;i<=n;i++)
			{
				if(a[i]>0)
				{
					--b[i]; 
					for(auto v:e[i])
						++b[v];
				}
			}
			swap(a,b);
			if(check())
			{
				cout << i << "\n";
				flag=1;
				break; 
			}
		}
		if(flag) continue;
		queue <int> q;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]==0)
			{
				dp[i]=1;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(auto v:E[x])
			{
				dp[v]=(dp[v]+dp[x])%mod;
				if(!--deg[v]) q.push(v);
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
			s+=dp[i]*a[i],s%=mod;
		cout << (s+X)%mod << "\n";
	}
	return 0;
}