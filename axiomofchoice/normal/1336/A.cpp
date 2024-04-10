#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define vector basic_string
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int sz[N],dep[N];
bool vis[N];
vector<int> a[N];
void dfs(int x){
	vis[x]=1;
	sz[x]=1;
	for(auto p:a[x])
	if(!vis[p]){
		dep[p]=dep[x]+1;
		dfs(p);
		sz[x]+=sz[p];
	}
}
int f(int x){
	return sz[x]-dep[x];
}
int n,k;
priority_queue<pair<ll,ll>> q;
signed main(){
	cin>>n>>k;
	repeat(i,0,n-1){
		int x,y; cin>>x>>y; x--,y--;
		a[x]+=y;
		a[y]+=x;
	}
	dep[0]=1;
	dfs(0);
	ll ans=0;
	q.push({f(0),0});
	fill(vis,vis+n,0);
	repeat(i,0,n-k){
		ans+=q.top().first;
		int x=q.top().second; q.pop(); vis[x]=1;
		for(auto p:a[x])
		if(!vis[p])
			q.push({f(p),p});
	}
	cout<<ans<<endl;
	return 0;
}