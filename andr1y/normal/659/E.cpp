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
bool hascycle = false;
ll w[N];
vector<ll> d[N];
void dfs(ll v, ll p = -1){
	w[v] = 1;
	for(auto i : d[v]){
		if(i == p) continue;
		if(w[i] == 0) dfs(i, v);
		if(w[i] == 1){
			hascycle = true;
			return;
		}
	}
	w[v] = 2;
}
main(){
    FAST;
    ll n, m;
    cin >> n >> m;
    for(ll i =0;i<m;i++){
    	ll u, v;
    	cin >> u >> v;
    	d[u].pb(v);
    	d[v].pb(u);
    }
    ll res = 0;
    for(ll i =1;i<=n;i++){
    	hascycle = 0;
    	if(w[i] == 0){
    		dfs(i, -1);
    		if(!hascycle) res++;
    	}
    }
    cout << res;
}