// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 202;
ll dp[N][N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	memset(dp, 0xff, sizeof(dp));
	dp[0][0][0]=0;
	for(ll i =0;i<n;i++){
        for(ll kst0=0;kst0<=i;kst0++){
            for(ll kstz=0;kstz<=i&&kstz<=k;kstz++){
                if(dp[i][kst0][kstz]==-1) continue;
                for(char tk = 'a';tk<='z';tk++){
                    ll nk  = kst0+(tk==t[0]?1:0);
                    ll nz  = kstz+(tk==s[i]?0:1);
                    ll nv  = dp[i][kst0][kstz]+(tk==t[1]?kst0:0);
                    if(nz<=k) dp[i+1][nk][nz] = max(dp[i+1][nk][nz], nv);
                    continue;
                }
            }
        }
	}
	/*for(ll i = 0;i<=n;i++){
        for(ll kst0=0;kst0<=n;kst0++){
            for(ll kstz=0;kstz<=k;kstz++){
                printf("dp[%I64d][%I64d][%I64d] = %I64d\n", i, kst0, kstz, dp[i][kst0][kstz]);
            }
        }
	}*/
    ll r=0;
    for(ll kst0=0;kst0<=n;kst0++){
        for(ll kstz=0;kstz<=k;kstz++){
            r=max(r, dp[n][kst0][kstz]);
        }
    }
    cout<<r<<'\n';
}