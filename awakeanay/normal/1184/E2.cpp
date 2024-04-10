 /*input
3 3
1 2 1
1 3 2
2 3 3
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
 
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;
 
int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}
 
int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}
 
int ceil1(int n,int k){
    return floor1(n+k-1,k);
}
 
const int N = 1e5+1;
const int LG = 17;
vector< pair< pair<int,int> ,pair<int,int> > > edges;
int n,m;
int sz[N];
vector< pair<int,int> > adj[N];
int pre[N][LG];
int cost[N][LG];
bool ismst[10*N];
int par[N];
int dist[N];
bool vis[N];
int ans[10*N];
 
int find(int x){
	if(par[x] == x)return x;
	par[x] = find(par[x]);
	return par[x];
}
 
void merge(int x,int y){
	 x= find(x);
	 y = find(y);
	if(sz[x] < sz[y])swap(x,y);
	par[y] = x;
	sz[x] += sz[y];
}
 
void dfs(int u,int p,int weight){
	pre[u][0] = p;
	cost[u][0] = weight;
	vis[u] = 1;
	//cout << "DFS ME" << " " <<  u << " " << weight << endl;
	RE(i,LG-1){
		pre[u][i] = pre[pre[u][i-1]][i-1];
		cost[u][i] = max(cost[u][i-1],cost[pre[u][i-1]][i-1]);
	}
	for(auto v:adj[u]){
		if(v.f == p)continue;
		dist[v.f] = dist[u]+1;
		if(vis[v.f])continue;
		dfs(v.f,u,v.s);
	}
	return;
}
 
int lca(int u,int v){
    if(dist[u] > dist[v])swap(u,v);
   
    int res = 0;
    for(int i = LG-1;i > -1;i--){
    	if(dist[v] >= dist[u]+ (1<<i) ){
    		res = max(res,cost[v][i]);
    		v = pre[v][i];
    	}
    }
 
    //lift both together 
    for(int j = LG-1;j > -1;j--){
    	if(pre[v][j] != pre[u][j]){
    		res = max(res,cost[v][j]);
    		res = max(res,cost[u][j]);
    		v = pre[v][j];
    		u = pre[u][j];
    	}
    }
    if(u != v){
    	res = max(res,cost[u][0]);res = max(res,cost[v][0]);
    	u = pre[u][0];v = pre[v][0];
    }
    return res;
}
 
void solve(){
  	cin >> n >> m;
  	REP(i,N){
  		adj[i].clear();
  		REP(j,LG){
  			pre[i][j] = cost[i][j] = 0;
  		}
  	}
  	REP(i,10*N){
  		ismst[i] = 0;
  	}
 	RE(i,n){
 		par[i] = i;
 		sz[i] = 1;
 	}
  	REP(i,m){
  		int a,b,c;cin >> a >> b >> c;
  		ismst[i] = 0;
  		edges.pb({{c,i},{a,b}});
  	}
  	sort(all(edges));
  	int summ = 0;
  	int added = 0;
  	REP(i,m){
  		if(added == n-1)continue;
  		if(find(edges[i].s.f) != find(edges[i].s.s)){
  			merge(edges[i].s.f,edges[i].s.s);
  			int a = edges[i].s.f;
  			int b = edges[i].s.s;
  			int c = edges[i].f.f;
  			added++;
  			//debug3(a,b,c);
  			summ += c;
  			ismst[edges[i].f.s] = 1;
  			adj[a].pb({b,c});
  			adj[b].pb({a,c});
  		}
  	}
  	//cout << "MST : " << summ << endl;
  	dfs(1,0,0);
  	REP(i,m){
  		if(ismst[edges[i].f.s])continue;
  		ans[edges[i].f.s] = lca(edges[i].s.f,edges[i].s.s);
  	}
  	REP(i,m){
  		if(!ismst[i])cout << ans[i] << "\n";
  	}
}
 
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("rand.txt","r",stdin);
  //freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}