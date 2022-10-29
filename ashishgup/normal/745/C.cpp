#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;

int n, m, k, ct=0;
int a[N], vis[N];
vector<int> g[N];

void dfs(int node)
{	
	if(vis[node])
		return;
	vis[node]=1;
	ct++;
	for(auto it:g[node])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int cur;
		cin>>cur;
		a[cur]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int sum=0;
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
	{	
		if(!a[i])
			continue;
		ct=0;
		dfs(i);
		sum+=ct;
		pq.push(ct);
	}
	int rem=n-sum;
	int best=pq.top();
	pq.pop();
	pq.push(best+rem);
	int ans=0;
	while(pq.size())
	{
		int cur=pq.top();
		pq.pop();
		ans+=(cur*(cur-1))/2;
	}
	ans-=m;
	cout<<ans;
}