#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n, m, s1, t1, l1, s2, t2, l2;
int vis[N][N], dist[N][N], ways[N][N];
vector<int> g[N];

void bfs(int k, int vis[], int dist[], int ways[])
{
	queue<int> q;
	q.push(k);
	ways[k]=1;
	vis[k]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis[it])
			{
				dist[it]=dist[node]+1;
				vis[it]=1;
				ways[it]+=ways[node];
				q.push(it);
			}
			else
			{
				if(dist[node]+1==dist[it])
				{
					ways[it]+=ways[node];
				}
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	for(int i=1;i<=n;i++)
		bfs(i, vis[i], dist[i], ways[i]);
	int rem=m+1;
	if(dist[s1][t1]<=l1 && dist[s2][t2]<=l2)
		rem=min(rem, dist[s1][t1] + dist[s2][t2]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int len1=dist[s1][i] + dist[i][j] + dist[j][t1];
			int len2=dist[s2][i] + dist[i][j] + dist[j][t2];
			if(len1<=l1 && len2<=l2)
				rem=min(rem, len1 + len2 - (dist[i][j]));
			len1=dist[s1][i] + dist[i][j] + dist[j][t1];
			len2=dist[s2][j] + dist[j][i] + dist[i][t2];
			if(len1<=l1 && len2<=l2)
				rem=min(rem, len1 + len2 - (dist[i][j]));
		}
	}
	int ans=m-rem;
	cout<<ans;
	return 0;
}