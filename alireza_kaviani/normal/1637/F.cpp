#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

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

int n , timer , tot , A[MAXN] , par[LOG][MAXN] , H[MAXN] , st[MAXN];
vector<int> adj[MAXN];
vector<pii> vec;
set<pii> S;
set<int> lca;

void DFS(int v , int p = 0){
	par[0][v] = p;
	H[v] = H[p] + 1;
	st[v] = timer++;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
	}
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
	if(u == v){
		return u;
	}
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int getDist(int v , int u){
	return H[v] + H[u] - 2 * H[LCA(v , u)];
}

void add(int v){
	lca.insert(v);
	S.erase({st[v] , v});
}

void insert(int v){
	if(SZ(S) == 0){
		tot = v;
		S.insert({st[v] , v});
		return;
	}
	auto it = S.lower_bound(pii(st[v] , -MOD));
	int prv = -1 , nxt = -1;
	if(it != S.begin()){
		prv = (*prev(it)).Y;
		add(LCA(v , prv));
	}
	if(it != S.end()){
		nxt = (*it).Y;
		add(LCA(v , nxt));
	}
	if(lca.find(v) == lca.end()){
		S.insert({st[v] , v});
	}
	tot = LCA(tot , v);
}

int check(){	
	int Slca = LCA((*S.begin()).Y , (*prev(S.end())).Y);
	if(Slca != tot){
		return 1;
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 1 ; j <= n ; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		vec.push_back({A[i] , i});
	}
	ll ans = 0;
	sort(all(vec), greater<pii>());
	insert(vec[0].Y);
	for(int i = 1 ; i < n ; i++){
//		cout << SZ(S) << endl;
		ans += (vec[i - 1].X - vec[i].X) * max(2ll , SZ(S) + check());
		insert(vec[i].Y);
	}
//	cout << SZ(S) << endl;
	ans += (vec[n - 1].X) * (SZ(S) + check());
	cout << ans << endl;

    return 0;
}
/*

*/