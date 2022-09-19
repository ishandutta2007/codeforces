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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll mark[MAXN], c[MAXN];

ll step = 1;
ll bl = 0, wh = 0;

vector<ll> G[MAXN];

ll pow_mod(ll base, ll power, ll mod){
	//debug(power);
	ll x;
	if(power == 0) return 1;
	if(power == 1) return base % mod;
	if(power % 2 == 0){
		x = pow_mod(base, power / 2, mod);
		return (x * x) % mod;
	}
	x = pow_mod(base, power / 2, mod);
	return (( (x * x) % mod ) * base) % mod;
}

bool DFS(ll node, ll col){
	c[node] = col;
	if(col == 1) bl ++;
	else wh ++;
	mark[node] = step;
	
	for(auto adj : G[node]){
		if(mark[adj] == step and c[node] == c[adj]) return false;
		if(mark[adj] == step) continue;
		
		if(DFS(adj, 3 - col) == false) return false;
	}
	return true;
}

void MAIN(){
	ll n, m;
	cin >> n;
	cin >> m;
	ll u, v;
	ll ans = 1;
	for(int i = 0; i<m;i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1; i<=n;i++){
		if(mark[i] < step) {
			bl = 0; wh = 0;
			if(DFS(i, 1) == false) ans = 0;
			else {
				ans = ans * ( pow_mod(2, bl, MOD) + pow_mod(2, wh, MOD) );
				ans %= MOD;
			}
		}
	}
	
	cout << ans << '\n';
	step ++;
	for(int i = 1; i<=n;i++) G[i].clear();

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T;
    cin >> T;
    while(T--) MAIN();
    return 0;
}