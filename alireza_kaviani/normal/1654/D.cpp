#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int q , n , dv[MAXN] , cnt[MAXN] , ans[MAXN];
ll val[MAXN];
vector<pair<int, pii>> adj[MAXN];
vector<int> vec;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

ll frac(ll x , ll y){
	return x * poww(y , MOD - 2) % MOD;
}

void add(int x , int v){
	while(x != 1){
		cnt[dv[x]] += v;
		ans[dv[x]] = min(ans[dv[x]] , cnt[dv[x]]);
		vec.push_back(dv[x]);
		x /= dv[x];
	}
}

void DFS(int v , int p = -1){
	for(pair<int , pii> i : adj[v]){
		int u = i.X , x = i.Y.X , y = i.Y.Y;
		if(u == p)	continue;
		add(x , -1); add(y , 1);
		DFS(u , v);
		add(x , 1); add(y , -1);
	}
}

void SolveDFS(int v , int p = -1){
	for(pair<int , pii> i : adj[v]){
		int u = i.X , x = i.Y.X , y = i.Y.Y;
		if(u == p)	continue;
		val[u] = val[v] * frac(y , x) % MOD;
		SolveDFS(u , v);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 2 ; i < MAXN ; i++){
		if(dv[i])	continue;
		for(int j = i ; j < MAXN ; j += i){
			dv[j] = i;
		}
	}

	cin >> q;
	while(q--){
		cin >> n;
		fill(adj , adj + n + 5 , vector<pair<int, pii>>());
		for(int i = 1 ; i < n ; i++){
			int v , u , x , y;
			cin >> v >> u >> x >> y;
			int g = __gcd(x , y);
			x /= g; y /= g;
			adj[v].push_back({u , {x , y}});
			adj[u].push_back({v , {y , x}});
		}
		DFS(1);
		ll res = 1 , sum = 0;
		for(int i : vec){
			if(ans[i] < 0){
				for(int j = 0 ; j < -ans[i] ; j++){
					res = res * i % MOD;
				}
			}
			ans[i] = cnt[i] = 0;
		}
		vec.clear();
		val[1] = res;
		SolveDFS(1);
		for(int i = 1 ; i <= n ; i++){
			sum += val[i];
		}
		cout << sum % MOD << endl;
	}

    return 0;
}
/*

*/