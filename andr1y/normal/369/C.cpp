#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100010
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
ll troubles[N];
map<pll, bool> is_trouble;
bool is_vertex_trb[N];
ll res = 0;
void dfs(ll v, ll P){
	for(auto i : d[v]){
		if(i==P) continue;
		ll tx = (is_trouble[{min(i, v), max(i, v)}] ? 1 : 0);
		dfs(i, v);
		troubles[v] += troubles[i] + tx;
		if(tx > 0) is_vertex_trb[i] = 1, res++;
	}
}
void dfs2(ll v, ll P){
	for(auto i : d[v]) if(i!=P) dfs2(i, v);
	if(is_vertex_trb[v] && troubles[v] > 0){
		is_vertex_trb[v] = 0;
		res--;
	}
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n-1;i++){
    	ll u, v, t;
    	cin >> u >> v >> t;
    	d[u].pb(v);
    	d[v].pb(u);
    	if(t == 2){
    		is_trouble[{min(u, v), max(u, v)}] = true;
    	}
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << res << endl;
    for(ll i =1;i<=n;i++){
    	if(is_vertex_trb[i]) cout << i << " ";
    }
}