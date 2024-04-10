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
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200200
#define INF 101111111111111
using namespace std;
ll a[N];
pll dp[N][2];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, p, k;
		cin >> n >> p >> k;
		for(ll i =0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		// ll tb = 0, tc = 0, res = (p >= a[0] ? 1 : 0);
		// p-=a[0];
		// for(ll i = 1;i<n && p > 0;i++){
		// 	if(a[i] <= p && tc < k){
		// 		tc++;
		// 		tb = a[i];
		// 	}else break;
		// 	if(tc == k){
		// 		p-=tb;
		// 		res++, tc = 0, tb = 0;
		// 	}
		// }
		//
		// dp[0][0] = {(p >= a[0] ? 1 : 0), p-a[0]}, dp[0][1] = {0, p};
		// ll res = 0;
		// if(dp[0][0].y >= 0) res = max(res, dp[0][0].x);
		// if(dp[0][1].y >= 0) res = max(res, dp[0][1].x);
		// for(ll i = 1;i<n;i++){
		// 	if(dp[i-1][0].y >= a[i] && dp[i][0].x < dp[i-1][0].x+1) dp[i][0] = {dp[i-1][0].x+1, dp[i-1][0].y-a[i]};
		// 	if(dp[i-1][1].y >= a[i] && dp[i][0].x < dp[i-1][1].x+1) dp[i][0] = {dp[i-1][1].x+1, dp[i-1][1].y-a[i]};
		// 	if(i == 1){
		// 		dp[i][1] = {(p >= a[1] ? 1 : 0), p-a[1]};
		// 	}else{
		// 		if(dp[i-2][0].y >= a[i] && dp[i][1].x < dp[i-2][0].x+1) dp[i][1] = {dp[i-2][0].x+2, dp[i-2][0].y-a[i]};
		// 		if(dp[i-2][1].y >= a[i] && dp[i][1].x < dp[i-2][1].x+1) dp[i][1] = {dp[i-2][1].x+2, dp[i-2][1].y-a[i]};
		// 	}
		// 	if(dp[i][0].y >= 0) res = max(res, dp[i][0].x);
		// 	if(dp[i][1].y >= 0) res = max(res, dp[i][1].x);
		// }
		ll res = 0;
		ll ss = 0;
		for(ll off = 0;off<k && ss <= p;off++){
			ll pos = off+k-1;
			ll ns= ss;
			while(pos < n && ns+a[pos] <= p){
				ns+=a[pos];
				pos +=k;
			}
			ss+=a[off];
			res = max(res, pos-k+1);
		}
		cout << res << endl;
	}
}