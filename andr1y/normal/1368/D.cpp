// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll cnt[28], a[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll a, i=0;i<n;i++){
        cin>>a;
        for(ll L = 0;L<20;L++){
            if(a&1) cnt[L]++;
            a>>=1;
        }
    }
    for(ll i = 0;i<n;i++){
        for(ll L = 0;L<20;L++){
            if(cnt[L]){
                cnt[L]--;
                a[i]+=(1LL<<L);
            }
        }
    }
    ll r=0;
    for(ll i = 0;i<n;i++){
        r+=a[i]*a[i];
    }
    cout<<r<<'\n';
}