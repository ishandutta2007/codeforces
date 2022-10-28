#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ct=0, ct0=0, ct1=0, atleast3=0;
int ans[N], color[N], sizes[N];
bool vis[N];
vector<int> g[N];

void dfs(int k, int col)
{
	if(vis[k])
	{
		if(color[k]!=col)
		{
			cout<<"0 1"; //Odd cycle length already exists
			exit(0); 
		}
		return;
	}
	ct++;
	ct0+=(col==0);
	ct1+=(col==1);
	vis[k]=1;
	color[k]=col;
	for(auto it:g[k])
		dfs(it, col^1);
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
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ct0=0;
			ct1=0;
			ct=0;
			dfs(i, 0);
			atleast3|=(ct>=3);
			ans[1]+=ct0*(ct0-1)/2 + ct1*(ct1-1)/2;
			sizes[ct]++;
		}
	}
	if(m==0) //All vertices are isolated
		cout<<3<<" "<<n*(n-1)*(n-2)/6;
	else if(atleast3)
		cout<<1<<" "<<ans[1];
	else
	{
		int answer=sizes[1] * sizes[2] + 4 * (sizes[2] * (sizes[2] - 1))/2;
		cout<<2<<" "<<answer;
	}
	return 0;
} 

// 0  1 
// 1  for each component, RC2 + BC2 
// 2  K components of size 1, (N-K)/2 components of size 2. R, B: RC1 * BC1 + BC2 * 4  
// 3  nC3