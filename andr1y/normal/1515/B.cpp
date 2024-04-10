// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
bool iskv(ll n){
    ll l = 1, r=1e9;
    while(r-l>1){
        ll m=(l+r)>>1;
        if(m*m>n) r=m;
        else l=m;
    }
    return l*l==n;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(n&1){
            cout<<"NO\n";
            continue;
        }
        bool a1 = iskv(n/2);
        bool a2 = ((n&3)==0?iskv(n/4):0);
        if(a1||a2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}