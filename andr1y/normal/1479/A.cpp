// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
const ll inf = 0x3fff3fff3fff3fff;
ll n;
ll e(ll i){
    if(i==0||i==n+1) return inf;
    if(!a[i]){
        cout<<"? "<<i<<endl;
        cin >> a[i];
    }
    return a[i];
}
signed main(){
    cin >> n;
    if(n==1){
        cout<<"! 1"<<endl;
        return 0;
    }
    if(e(1)<e(2)){
        cout<<"! 1"<<endl;
        return 0;
    }
    if(e(n-1)>e(n)){
        cout<<"! "<<n<<endl;
        return 0;
    }
    ll l =1, r=n;
    while(l<r){
        ll m = (l+r)>>1;
        if(e(m)>e(m+1)) l=m+1;
        else r=m;
    }
    cout<<"! "<<l<<endl;
}