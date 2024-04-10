// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        bool iak=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]==k) iak=1;
        }
        if(iak){cout<<"yes\n";continue;}
        ll g=0;
        for(ll i = 1;i<n;i++){
            g=__gcd(g, abs(a[i]-a[i-1]));
        }
        for(ll i = 0;i<n;i++){
            ll e = abs(a[i]-k);
            if(e%g==0) iak=1;
        }
        if(iak) cout<<"yes\n";
        else cout<<"no\n";
    }
}