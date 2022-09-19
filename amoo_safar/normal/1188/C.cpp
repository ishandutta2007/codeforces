#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> edge;

const int Maxn = 2e5 + 10;
ll Inf = 1e18;
const int Log = 20;
const ll Sqrt = 1000000;
const ll Mod = 998244353LL;

ll mul(ll a, ll b){
	a%=Mod;
	b%=Mod;
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}

ll a[Maxn];
ll X = 110000;
ll cnt[Maxn];
ll dp[1010][1010];

ll ps[1010][1010];



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -10000000;
	sort(a + 1, a + n + 1);
	ll mx = X / max(1LL, (k - 1));
	
	for(int i = 1; i <= mx; i++){
		for(int ii = 1; ii <= n; ii++) for(int j = 1; j <= k; j++) dp[ii][j] = 0, ps[ii][j] = 0;
		ll p1 = 0;
		dp[0][0] = 1;
		ps[0][0] = 1;
		for(int j = 1; j <= n; j++) ps[j][0] = 1;
		
		for(int j = 1; j <= n; j++){
			while(a[p1] + i <= a[j]){
				p1 ++;
			}
			p1 --;
			for(int K = 1; K <= k; K++){
				dp[j][K] = ps[p1][K - 1];
				ps[j][K] = (ps[j - 1][K] + dp[j][K]) % Mod;
			}
			cnt[i] += dp[j][k];
			cnt[i] %= Mod;
		}
		//if(cnt[i]) cerr << i << '\n';
	//	cerr << i << " : " << cnt[i] << '\n'; 
	}
	ll ans = 0;
	for(int i = 1; i <= mx; i++){
		ans += mul(i, cnt[i] - cnt[i + 1]);
		ans %= Mod;
	}
	ans += Mod;
	cout << ans % Mod;
	return 0;
}