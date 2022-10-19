#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pii , int> Data;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , k , m , timer , st[MAXN] , fn[MAXN] , H[MAXN] , par[LOG][MAXN] , V[MAXN] , U[MAXN] , S[MAXN] , col[MAXN] , dist[MAXN] , mark[MAXN];
vector<int> adj[MAXN];
vector<pii> g[MAXN];
priority_queue<Data , vector<Data> , greater<Data>> Q;

void PreDFS(int v , int p = 0){
	par[0][v] = p;
	st[v] = timer++;
	H[v] = H[p] + 1;
	for(int u : adj[v]){
		if(u == p)	continue;
		PreDFS(u , v);
	}
	fn[v] = timer;
}

int getPar(int v , int h){
	for(int i = 0 ; i < LOG ; i++){
		if(h & (1 << i)){
			v = par[i][v];
		}
	}
	return v;
}

int LCA(int v , int u){
	if(H[v] > H[u])	swap(v , u);
	u = getPar(u , H[u] - H[v]);
	if(v == u)	return v;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	PreDFS(1);
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 1 ; j <= n ; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}

	cin >> q;
	while(q--){
		cin >> k >> m;
		vector<pii> vec;
		vector<int> stk;
		for(int i = 1 ; i <= k ; i++){
			cin >> V[i] >> S[i];
			col[V[i]] = i;
			Q.push({{0 , i} , V[i]});
			vec.push_back({st[V[i]] , V[i]});
		}
		for(int i = 1 ; i <= m ; i++){
			cin >> U[i];
			vec.push_back({st[U[i]] , U[i]});
		}
		sort(all(vec));
		int sz = SZ(vec);
		for(int i = 1 ; i < sz ; i++){
			int lca = LCA(vec[i].Y , vec[i - 1].Y);
			vec.push_back({st[lca] , lca});
		}
		sort(all(vec));
		vec.resize(unique(all(vec)) - vec.begin());
		for(int i = 0 ; i < SZ(vec) ; i++){
			int v = vec[i].Y;
			while(SZ(stk) && fn[stk.back()] < fn[v]){
				stk.pop_back();
			}
			if(SZ(stk)){
				int u = stk.back() , w = H[v] - H[u];
				g[v].push_back({u , w});
				g[u].push_back({v , w});
//				cout << "Edge " << v << sep << u << sep << w << endl;
			}
			stk.push_back(v);
		}
		while(!Q.empty()){
			Data A = Q.top(); Q.pop();
			int time = A.X.X , color = A.X.Y , v = A.Y , speed = S[col[v]];
			if(mark[v])	continue;
			mark[v] = 1;
			for(pii i : g[v]){
				int u = i.X , w = i.Y , D = dist[v] + w;
				pii val = {(D + speed - 1) / speed , col[v]};
				if(col[u] == col[v])	continue;
				if(col[u] == 0 || val < pii({(dist[u] + S[col[u]] - 1) / S[col[u]] , col[u]})){
					dist[u] = D;
					col[u] = col[v];
					Q.push({{D / speed , col[v]} , u});
				}
			}
		}
		for(int i = 1 ; i <= m ; i++){
			cout << col[U[i]] << sep;
		}
		cout << endl;
		
		for(pii i : vec){
			int v = i.Y;
			col[v] = dist[v] = mark[v] = 0;
			g[v].clear();
		}
	}

    return 0;
}
/*

*/