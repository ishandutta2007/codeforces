// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, sai=0;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            sai+=a[i];
        }
        ll ans = n-1;
        for(ll parts=n;parts;parts--){
            if(sai%parts) continue;
            ll sp = sai/parts;
            ll bls=0, ok=1;
            for(ll i = 0;i<n;i++){
                bls+=a[i];
                if(bls>sp) ok=0;
                if(bls==sp) bls=0;
            }
            if(ok){
                ans=n-parts;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}