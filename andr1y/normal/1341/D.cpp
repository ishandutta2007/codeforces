//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2020;
bool dp[N][N];
bool d2[N][N];
ll need[N][10];
ll nums[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
ll a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	for(ll i = 1;i<=n;i++){
	    string s;
	    cin >> s;
        for(ll j = 0;j<7;j++){
            a[i]|=(s[j]-'0')*(1<<j);
        }
        for(ll j = 0;j<10;j++){
            ll k = nums[j]&a[i];
            ll e = a[i]^k;
            ll u = nums[j]^k;
            if(e!=0) need[i][j] = N;
            else need[i][j] = __builtin_popcount(u);
        }
	}
	dp[n+1][0] = 1;
	for(ll i = n;i>0;i--){
	    for(ll pl=0;pl<10;pl++){
	        if(need[i][pl] == N) continue;
	        ll np =need[i][pl];
	        for(ll from = 0;from<=k-np;from++){
	            dp[i][from+np] |= dp[i+1][from];
	        }
	    }
	}
	ll e = dp[1][k];
	if(!e){
        cout << -1;
        return 0;
	}
	string res = "";
	ll dd = 0;
    for(ll i = 1;i<n;i++){
        for(ll pl=9;pl>=0;pl--){
            if(need[i][pl] == N) continue;
            ll np =need[i][pl];
            if(dd+np<=k && dp[i+1][k-dd-np]){
                res += pl+'0';
                dd+=np;
                break;
            }
        }
    }
    for(ll pl=9;pl>=0;pl--){
        if(need[n][pl] == N) continue;
        ll np =need[n][pl];
        if(dd+np==k){
            res += pl+'0';
            break;
        }
    }
    cout << res << '\n';
}