#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b){
	return a-1 ? b - b*inv(b%a, a)/a : 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<ll>> dp(100, vector<ll>(100)),  ps(100,vector<ll>(100));
	dp[0][1] = 1;

	auto bin = [&](ll n, int k){
		ll p = 1, q = 1;
		rep(i,1,k+1){
			p = p * (n+1-i) % md;
			q = q * i % md;
		}
		return p*inv(q,md)%md;
	};

	rep(s,1,51){
		rep(a,0,s){
			int b = s-1-a;
			rep(x,1,a+2) rep(y,1,b+2)
				ps[s][min(x,y)] += dp[a][x]*dp[b][y] % md;
		}
		trav(x, ps[s]) x %= md;
		rep(x,1,s+2) rrep(a, 0, 51) rep(y,0,51)
			for(int i = 1; i*s+a <= 50 && i*x+y <= 50; ++i){
				dp[i*s+a][i*x+y] += dp[a][y]*bin(ps[s][x]+i-1,i) % md;
				dp[i*s+a][i*x+y] %= md;
			}
	}
	int n, m;
	cin >> n >> m;
	cout << dp[n][m] << endl;
}