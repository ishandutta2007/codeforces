#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<pll> G[MAXN];
ll a[MAXN], b[MAXN];
ll MN = 3e18;

ll mul(ll a, ll b){
	if(a > MN / b + 5) return MN;
	return a * b;
}

void DFS(ll u){
	ll adj, w;
	for(auto E : G[u]){
		adj = E.F; w = E.S;
		DFS(adj);
		if(a[adj] < b[adj]){
			ll x = b[adj] - a[adj];
			b[adj] -= x;
			b[u] += x;
		} else if(a[adj] > b[adj]){
			ll x = a[adj] - b[adj];
			b[adj] += x;
			b[u] -= mul(x, w);
			b[u] = max(b[u], -MN);
		}
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll u, w;
	for(int i = 2; i <= n; i++){
		cin >> u >> w;
		G[u].pb({i, w});
	}
	DFS(1);
	if(b[1] < a[1]) cout << "NO";
	else cout << "YES";
	return 0;
}

////////////////////////////////////////////// please don't use anti-hash anti-random tests;