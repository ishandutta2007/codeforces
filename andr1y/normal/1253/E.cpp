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
#define N 100005
#define INF 101111111111111
using namespace std;
ll dp[N];
pll a[85];
int main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i =0;i<n;i++) cin >> a[i].x >> a[i].y;
	dp[m] = 0;
	for(ll i = m-1;i>=0;i--){
		dp[i] = m-i;
		for(ll j = 0;j<n;j++){
			if(a[j].x-a[j].y <= i+1 && a[j].x + a[j].y >= i+1){
				dp[i] = dp[i+1];
				break;
			}
			else if(i < a[j].x-a[j].y){
				ll u = a[j].x-a[j].y-i-1;
				dp[i] = min(dp[i], dp[min(m, a[j].x+a[j].y+u)] + u);
			}
		}
	}
	cout << dp[0] << endl;
}