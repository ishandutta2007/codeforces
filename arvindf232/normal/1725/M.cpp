#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
#define rt return
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<"[ "<<(#W)<<" is "<<(W)<<" ]\n"
#define dbga(V) cerr<<"[ "<<(#V)<<": ";for(auto&i:V)cout<<i<<' ';cerr<<"]\n"
#define RTE cerr<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,-1,1};
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
//const int mod=998244353ll;
mt19937 mt(time(nullptr));
void solve(){
	int n,m;
	cin>>n>>m;
	tii edg[m];
	vector <pii> g[n+1];
	for (int i=0; i<m; i++){
		cin>>edg[i].x.x>>edg[i].x.y>>edg[i].y;
		g[edg[i].x.x].pb({edg[i].x.y,edg[i].y});
	}
	bool visited[n+1];
	for (int i=1; i<=n; i++) visited[i]=0;
	int dist[n+1];
	for (int i=1; i<=n; i++) dist[i]=1e18;
	dist[1]=0;
	priority_queue <pii,vector <pii>,greater <pii> > pq;
	pq.push({0,1});
	while (!pq.empty()){
		pii tp=pq.top(); pq.pop();
		if (visited[tp.y]) continue;
		visited[tp.y]=1;
		for (pii i:g[tp.y]){
			if (!visited[i.x]&&tp.x+i.y<dist[i.x]){
				dist[i.x]=tp.x+i.y;
				pq.push({dist[i.x],i.x});
			}
		}
	}
	for (int i=1; i<=n; i++) visited[i]=0;
	for (int i=1; i<=n; i++) g[i].clear();
	for (int i=0; i<m; i++){
		g[edg[i].x.y].pb({edg[i].x.x,edg[i].y});
	}
	for (int i=1; i<=n; i++) pq.push({dist[i],i});
	while (!pq.empty()){
		pii tp=pq.top(); pq.pop();
		if (visited[tp.y]) continue;
		visited[tp.y]=1;
		for (pii i:g[tp.y]){
			if (!visited[i.x]&&tp.x+i.y<dist[i.x]){
				dist[i.x]=tp.x+i.y;
				pq.push({dist[i.x],i.x});
			}
		}
	}
	for (int i=2; i<=n; i++){
		if (dist[i]==1e18) cout<<-1;
		else cout<<dist[i];
		cout<<' ';
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
	for (int i=1; i<=t; i++){
		solve();
	}
}