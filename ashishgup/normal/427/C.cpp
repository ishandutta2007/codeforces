#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, m, cnt=0;
int a[N], comp[N], vis[N];
vector<int> g[N], rg[N], v[N];
vector<int> todo;

void dfs(int k) 
{
	vis[k]=1; 
	for(auto it:g[k])
	{
		if(!vis[it])
		{
			dfs(it);
		}
	}
	todo.push_back(k);
}

void dfs2(int k,int val) 
{
	comp[k]=val;
	v[val].push_back(a[k]);
	for(int w: rg[k]) 
	{
		if(comp[w] == -1) 
		{
			dfs2(w,val);
		}
	}
}

void sccAddE(int from, int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc() 
{
	for(int i=1;i<=n;i++)
	{
		comp[i]=-1;
	}

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(todo.begin(),todo.end());

	for(int i: todo) 
	{
		if(comp[i]==-1) 
		{ 
			dfs2(i,i);
			cnt++; //Counts the number of Strongly Connected Components
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		sccAddE(u, v);
	}
	scc();
	int ans1=0;
	int ans2=1;
	for(int i=1;i<=n;i++)
	{
		if(!v[i].size())
			continue;
		sort(v[i].begin(), v[i].end());
		int min1=v[i][0];
		ans1+=min1;
		cnt = 0;
		for(auto it:v[i])
			if(it==min1)
				cnt++;
		ans2*=cnt;
		ans2%=MOD;
	}
	cout<<ans1<<" "<<ans2;
}