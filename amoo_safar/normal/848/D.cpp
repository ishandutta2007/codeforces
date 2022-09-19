#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

const ll Mod = 1e9 + 7;
const int Maxn = 52 + 3;

ll dp[Maxn][Maxn], dp2[Maxn][Maxn], dp3[Maxn][Maxn], dp4[Maxn][Maxn];
vector<pll> ord;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}
ll f[Maxn], iv[Maxn];
ll nCr(ll n, ll r){
	n += Mod; n %= Mod;
	if((n < r) || (r < 0)) return 0;
	ll res = iv[r];
	for(int i = 0; i < r; i++)
		res = mul(res, n - i);
	return res;
}

ll solve(ll cn, ll sm){
	if(cn == 0 && sm == 0) return 1;
	return nCr(cn - 1 + sm, sm);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < Maxn; i++) f[i] = mul(f[i - 1], i);
	for(int i = 0; i < Maxn; i++) iv[i] = inv(f[i]);
	
	
	ll N = 52;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			ord.pb({i, j});
	dp3[0][0] = 1;
	for(auto st : ord){
		int i = st.F, j = st.S;
		memset(dp4, 0, sizeof dp4);
		for(int cnt = 0; cnt <= N; cnt ++){
			ll nw = solve(dp2[i][j], cnt);
			if(nw == 0) continue;
			for(int n = 0; n + cnt * (i - 2) <= N; n++){
				for(int m = 0; m + cnt * j <= N; m++){
					dp4[n + cnt * (i - 2)][m + cnt * j] += mul(nw, dp3[n][m]);			
				}
			}
		}
		for(int n = 0; n <= N; n++)
			for(int m = 0; m <= N; m++) dp3[n][m] = dp4[n][m] % Mod;
		
		if(i < 2 || j < 1)
			dp[i][j] = 0;
		else 
			dp[i][j] = dp3[i - 2][j - 1];
		
		for(auto st2 : ord){
			if(st2.F == i && st2.S == j) break;
			if(N < i + st2.F - 1) continue;
			
			(dp2[i + st2.F - 1][min(j, st2.S)] += 2ll * dp[i][j] * dp[st2.F][st2.S]) %= Mod;
		}
		if(i + i - 1 <= N)
			(dp2[i + i - 1][j] += dp[i][j] * dp[i][j]) %= Mod;
	}
	
	
	ll n, m;
	cin >> n >> m;
	cout << dp[n + 2][m] << '\n';
	return 0;
}