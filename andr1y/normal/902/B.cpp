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
#define N 10010
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
ll pp[N];
ll nc = 0;
void dfs(ll v, ll p, ll now_color){
	if(now_color != pp[v]){
		now_color = pp[v];
		++nc;
	}
	for(auto i : d[v]){
		if(i!=p) dfs(i, v, now_color);
	}
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0, v;i<n-1;i++){
    	cin >> v;
    	d[i+2].pb(v);
    	d[v].pb(i+2);
    }
    for(ll i = 1;i<=n;i++) cin >> pp[i];
    dfs(1, -1, -1);
    cout << nc;
}