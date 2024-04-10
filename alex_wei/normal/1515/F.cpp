#include <bits/stdc++.h>
using namespace std;

#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define ll long long

ll n,m,x,s,vis[300005],a[300005];
vector <pii> e[300005];
deque <int> ans1,ans2;

void dfs(int id,int f,int ed){
	vis[id]=1;
	for(pii it:e[id])if(!vis[it.fi])dfs(it.fi,id,it.se);
	if(f){
		if(a[id]>=x)a[f]+=a[id]-x,ans1.pb(ed);
		else ans2.push_front(ed);
	}
}

int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	if(s<(n-1)*x)puts("NO"),exit(0); 
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		e[u].pb({v,i}),e[v].pb({u,i});
	} dfs(1,0,0),puts("YES");
	for(int it:ans1)cout<<it<<endl;
	for(int it:ans2)cout<<it<<endl;
	return 0;
}