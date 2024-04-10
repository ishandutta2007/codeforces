#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

ll a, b;
ll dp[65][2];

ll cur = 0;

ll calc(int n, int p){
	if(n == 60) return p == 0;
	ll &res = dp[n][p];
	if(res != -1) return res;
	if(b & (1ll<<n)){
		if(!p){
			if(a & ( 1ll<<n)) {
				res = calc(n+1, 0);	
			}else res = 0;
		}
		else {
			if(a & ( 1ll<<n)) res = 0;
			else {
				res = calc(n+1, 1);
			}
		}
	}else {
		if(p){
			if(a & ( 1ll<<n)) {
				res = calc(n+1, 0) | calc(n+1, 1);	
			}else res = 0;
		}
		else {
			if(a & ( 1ll<<n)) res = 0;
			else {
				res = calc(n+1, 0) | calc(n+1, 1);
			}
		}
	}
	return res;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    ll ans = calc(0, 0);
    if(ans){
    	ans = 1;
    	for(int i = 0; i < 60; i++){
    		if(b & (1ll<<i)) ans *= 2ll;
    	}
    	if(a == b)
	    	ans-=2;
    }
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}