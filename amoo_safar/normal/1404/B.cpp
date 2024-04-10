// That's How much we have in common
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

ll dis[5][N], nw = 0;
vector<ll> G[N];

void DFS(ll u, ll p, ll d){
	dis[nw][u] = d;
	for(auto adj : G[u]){
		if(adj != p)
			DFS(adj, u, d + 1);
	}
}

int Main(){
	ll n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	for(int i = 0; i <= n; i++) G[i].clear();
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	if(db <= da + da) return 1;

	nw = 0;
	DFS(a, -1, 0);
	if(dis[0][b] <= da) return 1;

	ll n1 = max_element(dis[0] + 1, dis[0] + n + 1) - dis[0];
	nw = 1;
	DFS(n1, -1, 0);
	ll R = *max_element(dis[1] + 1, dis[1] + n + 1);
	db = min(db, R);
	if(db <= da + da) return 1;
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) cout << (Main() ? "Alice\n" : "Bob\n");
	return 0;
}