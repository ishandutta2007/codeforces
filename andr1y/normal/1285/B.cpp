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
#define N 200200
#define INF 101111111111111LL
using namespace std;
using python = void;

ll dp[N][2][2];
signed main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		bool ok = 1;
		ll suma = 0;
		for(ll a, i = 0;i<n;i++){
			cin >> a;
			suma += a;
			if(i == 0){
				dp[i][1][0] = -INF, dp[i][1][1] = a;
				dp[i][0][0] = dp[i][0][1] = -INF;
			}else if(i == 1){
				dp[i][1][0] = dp[i-1][1][1], dp[i][1][1] = dp[i-1][1][1]+a;
				dp[i][0][0] = -INF, dp[i][0][1] = a;
			}else{
				// dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
				// dp[i][1] = max(a, dp[i-1][1]+a);

				dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1]);
				dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]);
				dp[i][0][1] = max(a, dp[i-1][0][1]+a);
				dp[i][1][1] = max(a, dp[i-1][1][1]+a);
			}
		}
		if(dp[n-1][0][1] < suma && dp[n-1][1][0] < suma && dp[n-1][0][0] < suma) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}