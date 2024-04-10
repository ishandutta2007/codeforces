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
#define N 200020
#define INF 101111111111111
using namespace std;
ll dp[N], res[N], res2[N];
pll a[N];
ll prev_d[N];
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++) {cin >> a[i].x; a[i].y = i;}
	sort(a, a+n);
	prev_d[0] = INF, prev_d[1] = INF;
	for(ll i = 2;i<n;i++){
		dp[i] = INF;
		prev_d[i] = INF;
		for(ll j = i-2;j>=i-4;j--){
			if(j < 0 || (j > 0 && j < 3)) continue;
			ll tres = a[i].x-a[j].x+(j > 0 ? dp[j-1] : 0);
			if(tres < dp[i]){
				dp[i] = tres;
				prev_d[i] = (j == 0 ? INF : j-1);
			}
		}
	}
	cout << dp[n-1] << " ";
	// vector<pll> cmd;
	ll cmc = 0;
	ll now = n-1;
	while(now != INF){
		// cmd.pb({now, prev_d[now]});
		cmc++;
		ll fx = prev_d[now];
		if(fx == INF) fx = -1;
		for(ll i = fx+1;i<=now;i++) res[i] = cmc;
		now = prev_d[now];
	}
	cout << cmc << endl;
	for(ll i = 0;i<n;i++){
		res2[a[i].y] = res[i];
	}
	for(ll i =0;i<n;i++) cout << res2[i] << " ";
		cout << endl;
}