// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((101*1000))
#define K (23)

ll n,sz[N][K];
vector <ll> e[N];
char ans[N];
bool mark[N];

ll centroid_find(ll x,ll h,ll size,ll par=0)
{
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!= par && !mark[e[x][i]] && sz[e[x][i]][h]>size/2)
			return centroid_find(e[x][i],h,size,x);
	return x;
}

void dfs(ll x,ll h,ll par=0)
{
	sz[x][h]=1;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && !mark[e[x][i]])
			dfs(e[x][i],h,x),sz[x][h]+=sz[e[x][i]][h];
}

void solve(ll x,ll h=0)
{
	dfs(x,h);
	ll v=centroid_find(x,h,sz[x][h]);
	mark[v]=1;ans[v]=h+'A';
	for(int i=0;i<e[v].size();i++)
		if(!mark[e[v][i]])
			solve(e[v][i],h+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	solve(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}