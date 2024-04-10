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
ll dp[N][2];
ll v[N];
int main(){
    FAST;
    ll T;
    cin >> T;
    while(T--){
    	ll n, a, b;
    	cin >> n >> a >> b;
    	for(ll i = 0;i<n;i++){
    		char c;
    		cin >> c;
    		v[i] = c-'0';
    	}
    	dp[0][0] = a+b;
    	dp[0][1] = a*2+b;
    	for(ll i = 1;i<n;i++){
    		dp[i][1] = min(dp[i-1][1]+2*b+a, (v[i] == 0 ? dp[i-1][0]+b+2*a : INF));
    		dp[i][0] = (v[i] == 1 ? INF : min(dp[i-1][1]+2*a+2*b, dp[i-1][0]+a+b));
    	}
    	cout << dp[n-1][0]+b << endl;
    }
}