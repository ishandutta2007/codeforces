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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Base[Log];


void Add(int x){
	for(int i = Log - 1; i >= 0; i--){
		if(x >> i & 1){
			x ^= Base[i];
			if(!Base[i]){
				Base[i] = x;
				return ;
			}
		}
	}
}

vector<pll> G[N];
int mk[N], dep[N];

void DFS(int u, int d = 0){
	mk[u] = 1;
	dep[u] = d;
	for(auto [adj, w] : G[u]){
		if(!mk[adj])
			DFS(adj, d ^ w);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector< pair<pll, int> > E;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
		E.pb({{u, v}, w});
	}
	DFS(1);
	for(auto [e, w] : E)
		Add(dep[e.F] ^ dep[e.S] ^ w);
	for(int i = Log - 1; i >= 0; i--){
		dep[n] = min(dep[n], dep[n] ^ Base[i]);
	}
	cout << dep[n] << '\n';
	return 0;
}