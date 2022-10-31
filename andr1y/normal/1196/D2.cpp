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
#define N 200000
#define INF 101111111111111
using namespace std;
char x[] = {'R', 'G', 'B'};
ll dp[N][3][3];
inline ll start_offset(ll l, ll r, ll off){
	return 0;
	if(r - l < 2){
		if(r - l == 0){
			if(l%3 == off) return 1;
			else return 0;
		}else{
			if(l%3 == off || r%3 == off) return 1;
			else return 0;
		}
	}
	while((l%3)!=off) l++;
	while((r%3)!=off) r--;
	return ((r-off)/3 - (l-off)/3 + 1);
}
int main(){
    FAST;
    ll Q;
    cin >> Q;
    while(Q--){
    	ll n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	if(k == 1){
    		cout << 0 << endl;
    		continue;
    	}else if(k<=10){
    		ll res = k;
	    	for(ll i = 0;i<n-k+1;i++){
	    		for(ll C = 0;C<3;C++){
	    			ll tr = 0;
	    			for(ll j = i;j<i+k;j++){
	    				char mbn = x[((j-i+C)%3)];
	    				if(mbn != s[j]) tr++;
	    			}
	    			res = min(res, tr);
	    		}
	    	}
    		cout << res << endl;
    		continue;
    	}
    	dp[0][0][0] = 0, dp[0][0][1] = 0, dp[0][0][2] = 0;
    	dp[0][1][0] = 0, dp[0][1][1] = 0, dp[0][1][2] = 0;
    	dp[0][2][0] = 0, dp[0][2][1] = 0, dp[0][2][2] = 0;
    	for(ll i = 0;i<n;i++){
    		dp[i][0][i%3] = (s[i] != 'R' ? 1 : 0); if(i > 2) dp[i][0][i%3] += dp[i-3][0][i%3];
    		dp[i][1][i%3] = (s[i] != 'G' ? 1 : 0); if(i > 2) dp[i][1][i%3] += dp[i-3][1][i%3];
    		dp[i][2][i%3] = (s[i] != 'B' ? 1 : 0); if(i > 2) dp[i][2][i%3] += dp[i-3][2][i%3];
    		for(ll j = 0;j<3;j++){
    			if(i%3 == j || i < 1) continue;
    			dp[i][0][j] = dp[i-1][0][j];
    			dp[i][1][j] = dp[i-1][1][j];
    			dp[i][2][j] = dp[i-1][2][j];
    		}
    	}
    	ll res = k;
    	for(ll i = 0;i<n-k+1;i++){
    		res = min(res, (dp[i+k-1][0][i%3] - (i>0?dp[i-1][0][i%3]:0)) + (dp[i+k-1][1][(i+1)%3] - (i>0?dp[i-1][1][(i+1)%3]:0)) + (dp[i+k-1][2][(i+2)%3] - (i>0?dp[i-1][2][(i+2)%3]:0)));
    		res = min(res, (dp[i+k-1][1][i%3] - (i>0?dp[i-1][1][i%3]:0)) + (dp[i+k-1][2][(i+1)%3] - (i>0?dp[i-1][2][(i+1)%3]:0)) + (dp[i+k-1][0][(i+2)%3] - (i>0?dp[i-1][0][(i+2)%3]:0)));
    		res = min(res, (dp[i+k-1][2][i%3] - (i>0?dp[i-1][2][i%3]:0)) + (dp[i+k-1][0][(i+1)%3] - (i>0?dp[i-1][0][(i+1)%3]:0)) + (dp[i+k-1][1][(i+2)%3] - (i>0?dp[i-1][1][(i+2)%3]:0)));
    	}
    	cout << res << endl;
    }
}