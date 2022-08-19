#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define pb push_back

vector<int> go[200];
vector<int> cost[200];
vector<bool> here[200];

int dfs(int v,int prev){
	int r=0;
	forn(i,2){
		int g=go[v][i];
		if(g==prev)
			continue;
		if(here[v][i])
			r+=cost[v][i];
		if(g==0)
			return r;
		return r+dfs(g,v);
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	forn(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		go[a].pb(b);
		cost[a].pb(c);
		here[a].pb(false);
		go[b].pb(a);
		cost[b].pb(c);
		here[b].pb(true);
	}
	cout<<min(dfs(0,go[0][0]),dfs(0,go[0][1]));

	return 0;
}