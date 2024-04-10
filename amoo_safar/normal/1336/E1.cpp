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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
ll CCC = 1;
vector<ll> G, A, B;
void Add(ll x){
	for(auto y : G) x = min(x, x ^ y);
	if(x) G.pb(x);
	else CCC = (2*CCC) % Mod;
	sort(all(G));
	reverse(all(G));
}

const ll NN = 210;
const ll D = 15;
const ll D2 = (1ll << D);
ll C[NN][NN];

ll X[(1<<21)+10];
ll X2[(1<<21)+10];
const ll K = 55;

ll dp2[K][D2 + 10];
ll dp1[K][D2 + 10];

ll dp[K][D + 2];
ll ans[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for(int i = 0; i < NN; i++)
		for(int j = 0; j <= i; j++)
			C[i][j] = (j ? C[i - 1][j - 1] + C[i - 1][j] : 1) % Mod;

	ll n, L;
	cin >> n >> L;
	//n = 200000;
	//L = 35;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		//a[i] = (1ll<<35)-1;
		Add(a[i]);
	}
	for(auto t : G){
		if(t < D2) A.pb(t);
		else B.pb(t);
	}

	ll m = B.size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < (1ll << i); j++) X[(1ll<<i) + j] = X[j] ^ B[i];
	}
	for(int i = 0; i < (1ll << m); i++){
		//cerr << (X[i]&(D2-1)) << ' ';
		dp2[__builtin_popcountll(X[i])][X[i] & (D2 - 1)] ++;
	}
	//cerr << '\n';
	m = A.size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < (1ll << i); j++) X2[(1ll<<i) + j] = X2[j] ^ A[i];
	}
	//cerr << '\n';
	for(int i = 0; i < (1ll << m); i++){
	//	cerr << X2[i] << ' ';
		dp1[__builtin_popcountll(X2[i])][X2[i]] ++;
	}
	//cerr << '\n';
	for(int i = 0; i < D; i++){
		for(int j = 0; j < D2; j++){
			if(j >> i & 1){
				for(int k = 0; k <= 35; k++){
					(dp2[k][j ^ (1ll << i)] += dp2[k][j]) %= Mod;
				}
				for(int k = 0; k <= 15; k++){
					(dp1[k][j ^ (1ll << i)] += dp1[k][j]) %= Mod;	
				}
			}
		}
	}

//	debug("A");
	for(int k1 = 0; k1 <= 15; k1++){
		for(int k2 = 0; k2 <= 35; k2++){
			for(int j = 0; j < D2; j++){
				//if(k2 == 35 && dp2[k2][j] != 1) cerr << j << " : " << dp2[k2][j] << '\n';
				(dp[k1 + k2][__builtin_popcount(j)] += (dp1[k1][j] * dp2[k2][j]) )%= Mod;
				
			}
		}
	}
	//cerr << dp1[0][0] << " " << dp2[35][0]<< '\n';
	//cerr << "!!" << dp[35][0] << '\n';
//	debug("B");
	for(int i = 0; i < K; i++){
		for(int j = D; j >= 0; j--){
			for(int j2 = j + 1; j2 < D + 2; j2++){
				dp[i][j] -= (dp[i][j2] * C[j2][j]) % Mod;
			}
			//cerr << i << " " << j << '\n';
			dp[i][j] %= Mod;
			dp[i][j] += Mod;
			dp[i][j] %= Mod;
			if(dp[i][j]){
				ans[i-j-j] += dp[i][j];
				ans[i-j-j] %= Mod;
			}
		}
	}
	for(int i = 0; i <= L; i++) cout << ((ans[i]%Mod)*CCC) % Mod << ' ';
	return 0;
}