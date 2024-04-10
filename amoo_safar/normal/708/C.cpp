#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 101;

ll n, sub[Maxn], mx[Maxn];
vector<ll> G[Maxn];

void DFS(ll u, ll p){
	sub[u] = 1;
	mx[u] = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		sub[u] += sub[adj];
		mx[u] = max(mx[u], sub[adj]);
	}
	mx[u] = max(mx[u], n - sub[u]);
}
ll val[Maxn];
void DFS2(ll u, ll p, ll v){
	val[u] = v;
	for(auto adj : G[u]){
		if(adj != p) DFS2(adj, u, v);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	ll cent = 1;
	for(int i = 1; i <= n; i++) if(mx[i] <= n/2) cent = i;
	DFS(cent, -1);
	ll mx1 = 0, mx2 = 0;
	for(auto adj : G[cent]){
		if(sub[adj] > mx1){
			mx2 = mx1;
			mx1 = sub[adj];
		} else {
			mx2 = max(mx2, sub[adj]);
		}
	}
	//cerr << mx1 << ' ' << mx2 << '\n';
	for(auto adj : G[cent]){
		if((sub[adj] == n/2) && (n % 2 == 0)) DFS2(adj, cent, n/2);
		else if(sub[adj] == mx1) DFS2(adj, cent, mx2);
		else DFS2(adj, cent, mx1);
	}
	//for(int i = 1; i <= n; i++) cerr << mx[i] << ' '; cerr << '\n';
	//for(int i = 1; i <= n; i++) cerr << val[i] << ' '; cerr << '\n';
	for(int i = 1; i <= n; i++){
		if((i == cent) || (mx[i] - val[i] <= n/2)) cout << "1 ";
		else cout << "0 ";
	}
	return 0;
}