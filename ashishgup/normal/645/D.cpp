#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, check=1;
int out[N], edges[N][2];
set<int> g[N];

void dfs(int k)
{
	int ct=0, store=-1, ct2=0;
	out[k]=0;
	for(auto it:g[k])
	{
		ct2++;
		if(out[it]==1)
		{
			ct++;
			store=it;
		}
		out[it]--;
	}
	if(ct!=1&&ct2>=1)
	{
		check=0;
		return;
	}
	if(store!=-1)
		dfs(store);
}

int check1(int k)
{
	check=1;
	for(int i=1;i<=n;i++)
	{
		out[i]=0;
		g[i].clear();
	}
	for(int i=1;i<=k;i++)
	{
		g[edges[i][1]].insert(edges[i][0]);
		out[edges[i][0]]++;
	}
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		if(!out[i])
			ct++;
	}
	if(ct!=1)
		return 0;
	for(int i=1;i<=n;i++)
	{
		if(!out[i])
		{
			dfs(i);
			break;
		}
	}
	if(!check)
	{
		return 0;
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	int check2=0;
	while(lo<=hi)
	{
		if(lo==hi)
			check2=1;
		int mid=(lo+hi)>>1;
		if(check1(mid))
			hi=mid;
		else
			lo=mid+1;
		if(check2)
			break;
	}
	if(check1(lo))
		return lo;
	else
		return -1;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		edges[i][0]=u;
		edges[i][1]=v;
	}
	int ans=binsearch(1, m);
	cout<<ans;
}