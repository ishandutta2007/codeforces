#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define N ((int)1010)
#define K ((int)61)

int n,sz[N],dis[N];
vector <int> e[N],values;
vector <pair<pair<int,int>,int> > res;

void pre_dfs(int x,int par=0)
{
	sz[x]=1;
	for(auto u:e[x])
		if(u!=par)
			pre_dfs(u,x),sz[x]+=sz[u];
}

int find_roid(int x,int par=0)
{
	for(auto u:e[x])
		if(u!=par && sz[u]>n/2)
			return find_roid(u,x);
	return x;
}

void dfs_value(int x,int par=0)
{
	for(auto u:e[x])
	{
		if(u==par)continue;
		res.push_back({{u,x},values.back()-dis[x]});
		dis[u]=values.back();
		values.pop_back();
		dfs_value(u,x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==1)return 0;
	if(n==2)return cout<<"1 2 1\n",0;
	for(int i=0;i<n-1;i++)
	{
		int v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	pre_dfs(1);
	int x=find_roid(1);
	pre_dfs(x);
	int k=0;
	vector <int> vec,vec2;
	vector <pair<int,int> > ex;
	
	for(auto u:e[x])
		ex.push_back({sz[u],u});
	sort(ex.begin(),ex.end());
	reverse(ex.begin(),ex.end());
	for(auto u:ex)
	{
		if(k<(n+2)/3)
		{
			k+=u.first;
			vec.push_back(u.second);
		}
		else
			vec2.push_back(u.second);
	}
	for(int i=k;i>=1;i--)values.push_back(i);
	for(auto u:vec)
	{
		res.push_back({{x,u},values.back()});
		dis[u]=values.back();
		values.pop_back();
		dfs_value(u,x);
	}
	for(int i=(n-k-1)*k;i>=k;i-=k)values.push_back(i);
	for(auto u:vec2)
	{
		res.push_back({{x,u},values.back()});
		dis[u]=values.back();
		values.pop_back();
		dfs_value(u,x);
	}
	for(auto u:res)
		cout<<u.first.first<<" "<<u.first.second<<" "<<u.second<<"\n";
	return 0;
}