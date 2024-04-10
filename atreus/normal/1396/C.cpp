#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

ll a[maxn], b[maxn], c[maxn], dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i]*r1+r3;
		c[i] = min(r2+r1, (a[i]+2)*r1);
		c[i] = min(c[i], b[i]);
	}
	dp[1] = b[1];
	dp[2] = min(dp[1]+d+b[2],c[1]+c[2]+3LL*d);
	for (int i = 3; i <= n; i++)
		dp[i] = min({dp[i-1]+d+b[i], dp[i-2]+c[i-1]+c[i]+4LL*d, dp[i-3]+c[i-2]+c[i-1]+c[i]+(6LL+(i>3))*d});
	ll now = min(b[n],c[n]+2*d);
	for (int i = n-1; i >= 1; i--){
		now += min(c[i],b[i]);
		dp[n] = min(dp[n], now+dp[i-1]+(2LL*(n-i+1)-1-(i==1))*d);
	}
	cout << dp[n] << endl;
}