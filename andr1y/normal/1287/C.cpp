#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 111
#define INF 101111111111111LL
using namespace std;
using python = void;

ll a[N], zp[N], n, dp[N][2][N][N];
vector<ll> unset;
bool st[N];
signed main(){
	FAST;
	cin >> n;
	unset.reserve(n);
	ll pn = 0, p2 = 0;
	for(ll i =1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0) {
			zp[i] = 1; 
			unset.pb(i);
		}else st[a[i]] = 1;
		zp[i] += zp[i-1];
	}
	for(ll i = 1;i<=n;i++){
		if(!st[i]){
			if(i&1) pn++;
			else p2++;
		}
	}
	for(ll i = 0;i<N;i++){
		for(ll j = 0;j<N;j++){
			for(ll k = 0;k<N;k++){
				dp[i][0][j][k] = dp[i][1][j][k] = INF;
			}
		}
	}
	if(a[1] == 0){
		dp[1][0][0][1] = (p2 > 0 ? 0 : INF), dp[1][1][1][0] = (pn > 0 ? 0 : INF);
	}else{
		dp[1][a[1]&1][0][0] = 0;
	}
	for(ll i = 2;i<=n;i++){
		for(ll j = 0;j<=min(pn, zp[i]);j++){
			ll k = zp[i] - j;
			if(k < 0 || k > p2) continue;
			if(a[i] == 0){
				dp[i][0][j][k] = min((k > 0 ? dp[i-1][0][j][k-1] : INF), (k > 0 ? dp[i-1][1][j][k-1]+1 : INF));
				dp[i][1][j][k] = min((j > 0 ? dp[i-1][0][j-1][k]+1 : INF), (j > 0 ? dp[i-1][1][j-1][k] : INF));
			}else{
				dp[i][a[i]&1][j][k] = min(dp[i-1][a[i]&1][j][k], dp[i-1][(~a[i])&1][j][k]+1);
			}
		}
	}
	ll res = n-1;
	for(ll j = 0;j<=pn;j++){
		ll k = zp[n] - j;
		if(k < 0 || k > p2) continue;
		res = min(res, (a[n] == 0 ? min(dp[n][0][j][k], dp[n][1][j][k]) : dp[n][a[n]&1][j][k]));
	}
	cout << res << endl;
}