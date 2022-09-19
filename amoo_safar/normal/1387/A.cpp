// Null
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
const ld EPS = 1e-6;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

void Sik(){
	cout << "NO\n";
	exit(0);
}

vector<pll> G[N];

vector<ld> Xs;

ll a[N], b[N];
ld ans[N];
int mk[N];

vector<ll> V, V2;
void DFS(int u){
	V.pb(u);
	mk[u] = 1;
	for(auto [adj, w] : G[u]){
		if(!mk[adj]){
			a[adj] = -a[u];
			b[adj] = w - b[u];
			DFS(adj);
		}
		if(a[u] == a[adj]){
			Xs.pb(((ld)(w - b[u] - b[adj])) / (2 * a[u]));
		} else {
			if(w != b[u] + b[adj]) Sik();
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}

	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		
		V.clear();
		Xs.clear();

		a[i] = 1;
		DFS(i);
		if(Xs.size() == 0){
			V2.clear();
			for(auto x : V) V2.pb(a[x] * b[x]);
			sort(all(V2));
			Xs.pb(-V2[V2.size() / 2]);
		}
		for(int i = 0; i + 1 < Xs.size(); i++) {
			if(abs(Xs[i] - Xs[i + 1]) > EPS) Sik();
		}
		for(auto x : V) ans[x] = a[x] * Xs[0] + b[x];


	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << setprecision(16) << ans[i] << " \n"[i == n];
	return 0;
}