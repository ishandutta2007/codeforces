//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
const ll M = 998244353;
ll dp[N], f[N], of[N];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (bpm(a*a, b>>1)*a)%M;
    else return bpm(a*a, b>>1);
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll t = max(n, k);
    f[0] = 1;
    for(ll i = 1;i<=t;i++) f[i]=(f[i-1]*i)%M;
    of[t] = bpm(f[t], M-2);
    for(ll i = t-1;i>=0;i--){
        of[i]=(of[i+1]*(i+1))%M;
    }
    ll res=0;
    for(ll i= 1;i<=n;i++){
        ll d = n/i;
        if(d<k) break;
        res+=(((f[d-1]*of[k-1])%M)*of[d-k])%M;
        res%=M;
    }
    cout<<res;
}