//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
map<ll, ll> cnt;
ll dp[20][N];
ll p[N];
ll mlog2[N];
ll aa[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	for(ll i =2;i<N;i++) mlog2[i] = mlog2[i>>1]+1;
    ll n;
    cin >> n;
    ll a = 0, rs= 0;
    cnt[0] = 0;
    for(ll c, i = 1;i<=n;i++){
        cin >> c;
        a+=c;
        aa[i]= c;
        p[i] = a;
        dp[0][i] = (cnt.count(a) ? cnt[a]+2 : 1);
        cnt[a]=i;
    }
    for(ll L = 1;L<20;L++){
        for(ll i = 0;i<=(n-(1<<L)+1);i++){
            dp[L][i] = max(dp[L-1][i], dp[L-1][i+(1<<(L-1))]);
        }
    }
    for(ll i =1;i<=n;i++){
        ll l =1, r = i;
        if(aa[i]==0) continue;
        while(r-l>1){
            ll m =(l+r)>>1;
            ll gg = max(dp[mlog2[i-m+1]][m], dp[mlog2[i-m+1]][i-(1<<mlog2[i-m+1])+1]);
            if(gg <=m) r = m;
            else l = m;
        }
        ll as = i+1;
        for(ll m = r;m>=l;m--){
            ll gg = max(dp[mlog2[i-m+1]][m], dp[mlog2[i-m+1]][i-(1<<mlog2[i-m+1])+1]);
            if(gg<=m) as = m;
        }
        rs+=i-as+1;
    }
    cout << rs << '\n';
}