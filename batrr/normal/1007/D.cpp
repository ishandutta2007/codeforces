#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9, LOG = 20, M = 1e7;

int sz;
int getid(){
	return sz++;
}
struct node{
    int id;
    node *l, *r;
    node (){
        id = getid();
        l = NULL;
        r = NULL;
    }
    node (int x){
        id = x;
        l = NULL;
        r = NULL;
    }
};
node* t[M];
vector< int > g[N], q[N], G[M], Gr[M], ord;
vector< pii > qq[N];
int timer, tin[N], tout[N], up[N][LOG];
int n, m;
int a[N], b[N];
bool was[M];
int comp[M];
void addEdge(int v, int u){
	//	cout << v << " " << u << endl;
	G[v].pb(u);
}
void DFS(int v, int p){
	up[v][0] = p;
	tin[v] = ++timer;
	for(int i = 1; i < LOG; i++)
		up[v][i] = up[ up[v][i - 1] ][i - 1];
	for(auto to : g[v])
		if(to != p)
			DFS(to, v);	
	tout[v] = timer;
}
bool upper(int v, int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v, int u){
	if(upper(v, u))
		return v;
	if(upper(u, v))
		return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[v][i], u))
			v = up[v][i];
	return up[v][0];		
}
int path(){
	int v, u, l, id;
    scanf("%d%d", &v, &u);
	//v = rand() % n + 1;
	//u = rand() % n + 1;
	l = lca(v,u);
	id = getid();
	if(v != l){
		q[v].pb(id);
		qq[l].pb({tin[v], id});
	}
	if(u != l){
		q[u].pb(id); 
		qq[l].pb({tin[u], id});
	}
	return id;
}
void fix(node *&v){                                       
	if(v -> l != NULL){
		addEdge(v -> l -> id << 1, v -> id << 1); 
		addEdge(v -> id << 1 ^ 1, v -> l -> id << 1 ^ 1); 
	}

	if(v -> r != NULL){
		addEdge(v -> r -> id << 1, v -> id << 1); 
		addEdge(v -> id << 1 ^ 1, v -> r -> id << 1 ^ 1); 
	}
	
	if(v -> l != NULL && v -> r != NULL){
		//cerr << "GG" << endl;
		addEdge(v -> l -> id << 1, v -> r -> id << 1 ^ 1);
		addEdge(v -> r -> id << 1, v -> l -> id << 1 ^ 1);
	}
}
void Merge(node *&v, node *&u, int l, int r){
	if(u == NULL)
		return;
    if(v == NULL){
    	v = u;
    	return;
    }
    if(l == r){
    	//cerr << l << endl;
    	assert(0);
    	v = NULL;
    	return;
    }
    v -> id = getid();
	int m = (l + r) / 2;        
	Merge(v -> l, u -> l, l, m);
	Merge(v -> r, u -> r, m + 1, r); 
	fix(v);
} 
void upd(node *&v, int l, int r, int pos){
	if(l == r){
		if(v == NULL){
			v = new node(pos);
		}else
			v = NULL;
		return;
	}
	if(v == NULL)
		v = new node();
	else
		v -> id = getid();
	int m = (l + r) / 2;        
	if(pos <= m)                 
		upd(v -> l, l, m, pos);
    else
		upd(v -> r, m + 1, r, pos);
	fix(v);
}
void build(int v, int p){
	int i = 0;
	sort(qq[v].begin(), qq[v].end());
    for(auto to : g[v]){
		if(to == p)	
			continue;
		build(to, v);
		while(i < qq[v].size() && qq[v][i].f <= tout[to]){
			//cerr << to << " " << qq[v][i].f << " " << qq[v][i].s << " " << tout[to] << endl;
			upd(t[to],0, 2 * m - 1, qq[v][i++].s);          
		}
		Merge(t[v], t[to], 0, 2 * m - 1);
	}
	for(auto it : q[v]){
		//cerr << v << " " << it << endl;
		upd(t[v], 0, 2 * m - 1, it);
	}
}

void dfs(int v){
	if(was[v])
		return;
	was[v] = 1;
	for(auto to : G[v])
		dfs(to);	
	ord.pb(v);
}
void dfsr(int v, int c){
	if(comp[v])
		return;
	comp[v] = c;
	for(auto to : Gr[v])
		dfsr(to, c);	
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		//v = i + 1;
		//u = rand() % i + 1;
		g[v].pb(u);
		g[u].pb(v);
	}
	DFS(1, 1);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		a[i] = path();
		b[i] = path();
		addEdge(a[i] << 1 | 1, b[i] << 1);
		addEdge(b[i] << 1 | 1, a[i] << 1);
	}
	build(1, 1);               
	sz <<= 1;
	for(int i = 0; i < sz; i++)
		dfs(i);
	for(int i = 0; i < sz; i++)
		for(auto j : G[i])
			Gr[j].pb(i);
	for(int i = sz - 1, j = 1; i >= 0; i--)
		dfsr(ord[i], j++);

	
	for(int i = 0; i < sz; i++)
		if(comp[i] == comp[i ^ 1]){
			//cerr << comp[i] << " " << i << endl;
			puts("NO");
			return 0;
		}
	
	puts("YES");
	for(int i = 0; i < m; i++){
		a[i] <<= 1;
		b[i] <<= 1;
		//cerr << a[i] << " " << b[i] << endl;
        if(comp[a[i]] > comp[a[i] ^ 1])
			puts("1");
		else
			puts("2");
	}
	return 0;
}