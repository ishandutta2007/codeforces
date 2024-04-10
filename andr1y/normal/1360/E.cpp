//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 51;
ll a[N][N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
	    ll n;
	    cin >> n;
	    for(ll i = 0;i<n;i++){
	        for(ll j = 0;j<n;j++){
	            char c;
	            cin >> c;
	            if(c=='0') a[i][j]=0;
	            else a[i][j]=1;
	        }
	    }
        bool ok = 1;
        for(ll diag=2*n-2;diag>=0;diag--){
            ll len = (diag<n?diag+1:2*n-1-diag);
            ll r = (diag<n?0:diag-n+1), c = (diag<n?diag:n-1);
            for(ll i = 0;i<len;i++){
                if(a[r][c]){
                    if(!(r+1==n||c+1==n||a[r+1][c]||a[r][c+1]))ok=0;
                }
                ++r, --c;
            }
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
	}
}