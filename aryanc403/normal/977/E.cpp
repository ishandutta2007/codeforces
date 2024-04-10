
//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007

    LLI T,n,in,i,m,j,k,x,y;
    vector <LLI> ed[200005],a,b;
    vector <LLI> :: iterator it;
    bool yes,vis[200005];

void dfs(LLI u)
{
	if(vis[u])
		return;
	if(ed[u].size()!=2)
		yes=false;
	
	vis[u]=true;
	
	for(LLI i=0;i<ed[u].size();++i)
	{
		dfs(ed[u][i]);
	}
}

void DFS(LLI u)
{
	if(vis[u]==false)
		return;
	
	vis[u]=false;
	b.pb(u);
	for(LLI i=0;i<ed[u].size();++i)
	{
		DFS(ed[u][i]);
	}
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    LLI r,c;
    fo(i,m)
    {
    	cin>>x>>y;
    	ed[x].pb(y);
    	ed[y].pb(x);
	}
	
	for(i=1;i<=n;++i)
	{
		if(vis[i])
			continue;
		yes=true;
		dfs(i);
		if(yes)
			a.pb(i);
	}
	
	/*for(i=0;i<a.size();++i)
	{
		if(vis[a[i]]==false)
			continue;
		DFS(a[i]);
	}*/
	//sort(b.begin();b.end());
	cout<<a.size();
	
    return 0;
}