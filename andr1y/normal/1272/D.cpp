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
#define N 200005
#define INF 101111111111111
using namespace std;
ll dp[N][2], a[N];
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(ll i = 1;i<=n;i++){
		if(i == 1){
			dp[i][0] = 1, dp[i][1] = 1;
		}else if(i == 2){
			dp[i][0] = 1 + (a[1] < a[2] ? 1 : 0), dp[i][1] = dp[i][0];
		}else{
			dp[i][0] = 1+(a[i-1] < a[i] ? dp[i-1][0] : 0);
			dp[i][1] = max((a[i-2] < a[i] ? dp[i-2][0] + 1 : 1), max(dp[i][0], (a[i-1] < a[i] ? 1+dp[i-1][1] : 1)));
		}
	}
	ll mr = 0;
	for(ll i = 1;i<=n;i++) mr = max(mr, max(dp[i][0], dp[i][1]));
		cout << mr << endl;
}