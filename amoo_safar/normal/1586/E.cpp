// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<int> G[N];
int mk[N];
vector<vector<int>> ans;
int par[N], dep[N];

void DFS(int u, int p, int d){
	par[u] = p;
	dep[u] = d;
	mk[u] = 1;
	for(auto adj : G[u]){
		if(mk[adj]) continue;
		DFS(adj, u, d + 1);
	}
}

void Go(int u, int v){
	vector<int> A, B;
	while(u != v){
		if(dep[u] <= dep[v]){
			B.pb(v);
			v = par[v];
		} else {
			A.pb(u);
			u = par[u];
		}
	}
	A.pb(u);
	reverse(all(B));
	for(auto x : B) A.pb(x);
	ans.pb(A);
}
int deg[N];
int Main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, 0, 0);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> u >> v;
		deg[u] ++;
		deg[v] ++;
		Go(u, v);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(deg[i] % 2 == 1) cnt ++;
			
	if(cnt)
		return cout << "NO\n" << cnt/2 << '\n', 0;
	cout << "YES\n";
	for(auto v : ans){
		cout << v.size() << '\n';
		for(auto x : v) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}