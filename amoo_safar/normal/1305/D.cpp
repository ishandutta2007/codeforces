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

vector<ll> G[N], B;
ll mk[N];
void DFS(ll u, ll p){
	ll s = (u == p ? 0 : 1);
	for(auto adj : G[u]){
		if(adj == p || mk[adj] == 1) continue;
		DFS(adj, u);
		s ++;
	}
	if(s <= 1){
		B.pb(u);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	while(true){
		B.clear();
		ll r = 1;
		for(int i = 1; i <= n; i++) if(!mk[i]) r = i;

		DFS(r, r);
		if(B.size() == 1){
			cout << "! " << B[0] << endl;
			break;
		}
		u = B[0];
		v = B[1];
		cout << "? " << u << " " << v << endl;
ll ans;
		cin >> ans;
		if(ans == u){
			cout << "! " << u << endl;
			break;
		}
		if(ans == v){
			cout << "! " << v << endl;
			break;
		}
		mk[u] = 1;
		mk[v] = 1;
	}
	return 0;
}