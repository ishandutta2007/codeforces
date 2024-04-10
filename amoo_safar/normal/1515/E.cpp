// vaziat meshki-ghermeze !
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

// const ll Mod = 1000000007LL;
const int N = 4e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll md;

ll mul(ll a, ll b){
	return (a * b) % md;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(int j = 1, pw = b; j <= p; pw = mul(pw, pw), j <<= 1)
		if(p & j)
			res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, md - 2);
}

ll dp[2][N][N];
ll tmp[N][N];
ll iv[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n >> md;
	for(int i = 1; i < N; i++) iv[i] = inv(i);
	ll ans = 0;
	
	dp[1][1][1] = 1;
	for(int i = 2; i <= n; i++){
		memset(tmp, 0, sizeof tmp);
		int ii = i & 1;
		for(int cnt = 1; cnt <= i; cnt ++){
			for(int sm = cnt; sm <= i; sm ++){
				if(cnt > 1)
					tmp[cnt][sm] = mul(2, mul(dp[ii ^ 1][cnt - 1][sm - 1], mul(sm, iv[cnt])));
				else {
					for(int k = 1; k <= sm; k ++)
						tmp[cnt][sm] += dp[ii][k][sm - 1];
					tmp[cnt][sm] %= md;
					tmp[cnt][sm] = mul(tmp[cnt][sm], sm);
				}
				if(i == n) ans += tmp[cnt][sm];
				// if(tmp[cnt][sm])
					// cerr << "! " << i << ' ' << cnt << ' ' << sm  << " -> " << tmp[cnt][sm] << '\n';
			}
		}
		memcpy(dp[ii], tmp, sizeof tmp);
	}
	cout << ans % md << '\n';
	return 0;
}