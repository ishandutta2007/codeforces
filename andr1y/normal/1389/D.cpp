// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if(l1>l2||(l1==l2&&r1>r2)){
            swap(l1, l2);
            swap(r1, r2);
        }
        ll fee=0, cd1=0, r=0, inter=0;
        fee=max(0ll, l2-r1);
        inter=max(0ll, min(r1, r2)-max(l1, l2));
        k-=inter*n;
        k=max(k, 0ll);
        cd1 = max(r1, r2)-min(l1, l2)-inter;
        r=fee;
        ll v = min(cd1, k);
        r+=v;
        k-=v;
        for(ll i = 1;i<n&&k;i++){
            ll nn = min(cd1, k);
            ll vv = fee+nn;
            if(vv<=nn+nn){
                r+=vv;
                k-=nn;
            }else{
                r+=nn+nn;
                k-=nn;
            }
        }
        if(k) r+=k+k;
        cout<<r<<'\n';
    }
}