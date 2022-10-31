// -- //
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N = 3e5+228;
const ll N2 = 9e6+228;
ll a[N];
ll zc[N2], oc[N2];
ll tn=1;
ll to[N2][2];
void insert(ll num){
    ll root=0;
    for(ll bit=30;bit>=0;bit--){
        ll bv = (num>>bit)&1;
        if(!to[root][bv]) to[root][bv]=tn++;
        root=to[root][bv];
    }
}
ll c[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        insert(a[i]);
    }
    ll x=0;
    long long ar=0;
    for(ll bit = 30;bit>=0;bit--){
        long long rn = 0, rinv=0;
        for(ll i = 0;i<n;i++){
            ll bv = (a[i]>>bit)&1;
            if(bv){
                rinv+=zc[c[i]];
                oc[c[i]]++;
            }else{
                rn+=oc[c[i]];
                zc[c[i]]++;
            }
            c[i]=to[c[i]][bv];
        }
        if(rinv<rn){
            x|=1LL<<bit;
            ar+=rinv;
        }else{
            ar+=rn;
        }
    }
    cout<<ar<<' '<<x;
}