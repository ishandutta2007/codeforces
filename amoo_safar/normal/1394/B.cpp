// Zende bad Shoma nasime faghat !
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

ll n, m, k;

const int K = 10;
bool bad[K][K][K][K];
vector<pll> I[N];
vector<pll> G[N];

int C[K];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	ll u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].pb({w, v});
	}
	for(int i = 1; i <= n; i++){
		sort(all(G[i]));
		int d = G[i].size();
		for(int j = 0; j < d; j++){
			I[G[i][j].S].pb({d, j + 1});
		}
	}
	vector<pll> V;
	for(int i = 1; i <= n; i++){
		sort(all(I[i]));
		V.clear();
		for(auto X : I[i]){
			for(auto Y : V){
				bad[X.F][X.S][Y.F][Y.S] = bad[Y.F][Y.S][X.F][X.S] = true;
			}
			if(V.empty()) V.pb(X);
			if(V.back() != X) V.pb(X);
		}
	}
	vector<int> P(k); iota(all(P), 1);

	ll ans = 0;
	do {
		for(int i = 0; i < k; i++){
			C[i] = 1;
			for(int j = 0; j < i; j++) if(P[j] > P[i]) C[i] ++;
		}
		bool flg = true;
		for(int i = 0; i < k; i++)
			for(int j = 0; j < k; j++)
				if(bad[i + 1][C[i]][j + 1][C[j]])
					flg = false;
		if(flg) ans ++;

	} while(next_permutation(all(P)));

	cout << ans << '\n';
	return 0;
}