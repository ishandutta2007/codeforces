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

const ll MAXN = 1e5 + 10;
const ll MAXM = 310;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , timer , st[MAXN] , fn[MAXN] , H[MAXN] , mark[MAXN] , par[LOG][MAXN] , dp[MAXN][MAXM];
ll fact[MAXN] , inv[MAXN];
vector<int> adj[MAXN];

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

ll C(int n , int r){
	if(r > n || r < 0)	return 0;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int cmp(int v , int u){
	return st[v] < st[u];
}

void PreDFS(int v , int p = 0){
	par[0][v] = p;
	st[v] = timer++;
	H[v] = H[p] + 1;
	for(int u : adj[v]){
		if(u != p){
			PreDFS(u , v);
		}
	}
	fn[v] = timer;
}

int getPar(int v , int h){
	for(int i = 0 ; i < LOG ; i++){
		if(h & (1 << i)){
			v = par[i][v];
		}
	}
	return v;
}

int LCA(int v , int u){
	if(H[v] > H[u])	swap(v , u);
	u = getPar(u , H[u] - H[v]);
	if(v == u)	return v;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

void SolveDFS(int v , int p = -1){
	for(int i = 0 ; i < MAXM ; i++){
		dp[v][i] = (mark[v] ? i : 1);
	}
	for(int u : adj[v]){
		if(u == p)	continue;
		SolveDFS(u , v);
//		cout << v << sep << u << endl;
		for(int i = mark[v] ; i < MAXM ; i++){
			dp[v][i] = 1ll * dp[v][i] * dp[u][i - mark[v]] % MOD;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	fact[0] = 1;
	for(int i = 1 ; i < MAXN ; i++)	fact[i] = fact[i - 1] * i % MOD;
	inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
	for(int i = MAXN - 2 ; i >= 0 ; i--)	inv[i] = inv[i + 1] * (i + 1) % MOD;

	cin >> n >> q;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	PreDFS(1);
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 1 ; j <= n ; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		adj[i].clear();
	}
	while(q--){
		vector<int> vec , stk;
		int k , m , r;
		cin >> k >> m >> r;
		for(int i = 0 ; i < k ; i++){
			int x;
			cin >> x;
			mark[x] = 1;
			vec.push_back(x);
		}
		vec.push_back(r);
		sort(all(vec) , cmp);
		for(int i = 0 ; i < k ; i++){
			vec.push_back(LCA(vec[i] , vec[i + 1]));
		}
		sort(all(vec) , cmp);
		vec.resize(unique(all(vec)) - vec.begin());
		for(int i : vec){
//			cout << i << endl;
			while(stk.size() > 0 && fn[stk.back()] < fn[i]){
				stk.pop_back();
			}
			if(stk.size() > 0){
//				cout << "Edge " << i << sep << stk.back() << endl;
				adj[i].push_back(stk.back());
				adj[stk.back()].push_back(i);
			}
			stk.push_back(i);
		}
		SolveDFS(r);
		int ans = 0;
		for(int i = 0 ; i <= m ; i++){
			for(int j = 0 ; j < i ; j++){
				dp[r][i] = (dp[r][i] + MOD - C(i , j) * dp[r][j] % MOD) % MOD;
			}
			//cout << dp[r][i] << endl;
			ans = (ans + inv[i] * dp[r][i]) % MOD;
		}
		cout << ans << endl;
		for(int i : vec){
			mark[i] = 0;
			adj[i].clear();
		}
		//cout << "============" << endl;
	}

    return 0;
}
/*

*/