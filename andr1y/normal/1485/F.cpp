// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 1e9+7;
map<ll, ll> endss;
ll dp[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        endss.clear();
        ll ts=0;
        dp[0]=1;
        for(ll b, i =0;i<n;i++){
            cin >> b;
            if(!i){
                endss[b]=1;
                continue;
            }
            ll e = (dp[i-1] + M - endss[ts])%M;
            dp[i] = (dp[i-1] + e)%M;
            ts-=b;
            endss[ts+b]+=e;
            endss[ts+b]%=M;
        }
        cout<<dp[n-1]<<'\n';
    }
}