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
vector<vector<pair<int,int> > > adj(N+2);
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
 
 
//--------------------------------------

struct segMinL{ //with lazy, beaware of max value = INT_MAX/3
	const int INF = 1e9;
	vector<int> tree, lazy;
	int size;
	segMinL(int size){
		this->size = size;
		tree = vector<int>(size*4 + 1, INF);
		lazy = vector<int>(size*4 + 1, INF);
	}
	
	segMinL(vector<int>& arr){
		this->size = arr.size();
		tree = vector<int>(size*4 + 1, 0);
		lazy = vector<int>(size*4 + 1, INF);
		init(1, 0, size-1, arr);
	}
	
	void init(int i, int start, int end, vector<int>& arr){
		if(start == end){
			tree[i] = arr[start];
			return;
		}
		int m = (start + end)/2;
		init(i*2, start, m, arr);
		init(i*2+1, m+1, end, arr);
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}
	
	void prop(int i, int start, int end){
		tree[i] = min(tree[i], lazy[i]);
		if(start != end){
			lazy[i*2] = min(lazy[i*2], lazy[i]);
			lazy[i*2 + 1] = min(lazy[i*2 + 1], lazy[i]);
		}
		lazy[i] = INF;
	}
	
	int query(int i, int s, int e, int l, int r){
		prop(i, s, e);
		if(s >= l && e <= r){
			return tree[i];
		}
		if(e < l || s > r) return INF;
		int m = (s + e)/2;
		return min(query(i*2, s, m, l, r), query(i*2+1, m+1, e, l, r));
	}
	
	void upd(int i, int s, int e, int l, int r, int val){
		prop(i, s, e);
		if(s >= l && e <= r){
			lazy[i] = min(lazy[i], val);
			prop(i,s, e);
			return;
		}
		if(s > r || e < l) return;
		int m = (s + e)/2;
		upd(i*2, s, m, l, r, val);
		upd(i*2+1, m+1, e, l, r, val);
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}	
	
	int query(int l, int r){
		return query(1, 0, size-1, l, r);
	}
	void upd(int l, int r, int val){
		upd(1, 0, size-1, l, r, val);
	}
} segtree(N+100);


vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfsHLD(int v, vector<vector<pair<int, int> >> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (auto d : adj[v]) {
    	int c = d.f;
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfsHLD(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h, vector<vector<pair<int, int> >> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (auto c : adj[v]) {
        if (c.f != parent[v] && c.f != heavy[v])
            decompose(c.f, c.f, adj);
    }
}

void init(vector<vector<pair<int, int> >> const& adj) {
    int n = N;
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfsHLD(1, adj);
    decompose(1, 1, adj);
}


void query(int a, int b, int val) {
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        segtree.upd(pos[head[b]], pos[b], val);
    }
    if (depth[a] > depth[b])
        swap(a, b);
        
    if(pos[a]+1<= pos[b]){
    	//cout<<"QRY "<<pos[a]+1<<" "<<pos[b]<<endl;
		segtree.upd(pos[a]+1, pos[b], val);
		//cout<<"AFTER "<<segtree.query(1, 1)<<endl;
	}
    	
}


//--------------------------------------

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
  	init(adj);
  	
  	REP(i,m){
  		if(ismst[edges[i].f.s]){
  			continue;
		}else{
  			ans[edges[i].f.s] = lca(edges[i].s.f,edges[i].s.s);
  			query(edges[i].s.f, edges[i].s.s, edges[i].f.f);
		}
  	}
  	
  	REP(i, m){
  		if(ismst[edges[i].f.s] == false) continue;
  		int vert = 	edges[i].s.f;
  		if(dist[vert] < dist[edges[i].s.s]) vert = edges[i].s.s;
  		ans[edges[i].f.s] = segtree.query(pos[vert], pos[vert]);
  		//cout<<"EDGE "<<edges[i].f.s<<" "<<vert<<" "<<pos[vert]<<endl;
	}
  	REP(i,m){
  		cout <<ans[i] << "\n";
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