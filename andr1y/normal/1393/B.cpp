// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll cnt[N];
ll fwt[N];
void fwinc(ll p, ll d){
    if(p==0) return;
    for(;p<N;p+=p&-p) fwt[p]+=d;
}
ll fwsum(ll r, ll s=0){
    for(;r;r-=r&-r) s+=fwt[r];
    return s;
}
ll fwsumlr(ll l, ll r){
    return fwsum(r)-fwsum(l-1);
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll a, i = 0;i<n;i++){
        cin >> a;
        fwinc(cnt[a], -1);
        cnt[a]++;
        fwinc(cnt[a], 1);
    }
    ll q;
    cin >> q;
    while(q--){
        char code;
        ll a;
        cin >> code >> a;
        if(code=='+'){
            fwinc(cnt[a], -1);
            cnt[a]++;
            fwinc(cnt[a], 1);
        }else{
            fwinc(cnt[a], -1);
            cnt[a]--;
            fwinc(cnt[a], 1);
        }
        ll v8 = fwsumlr(8, N-1);
        ll v6 = fwsumlr(6, N-1);
        ll v4 = fwsumlr(4, N-1);
        ll v2 = fwsumlr(2, N-1);
        if(v8>0) cout<<"YES\n";
        else if(v6>1||(v6==1&&v2-v6>0)) cout<<"YES\n";
        else if(v4>1||(v4==1&&v2-v4>1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}