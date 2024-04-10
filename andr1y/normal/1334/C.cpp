//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll a[N], b[N], c[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll sai = 0;
        for(ll i =0;i<n;i++){
            cin >> a[i] >> b[i];
            sai+=a[i];
            if(i) c[i] = max(0ll, a[i]-b[i-1]);
        }
        c[0] = max(0ll,a[0]-b[n-1]);
        ll sc = 0;
        for(ll i =0;i<n;i++) sc+=c[i];
        for(ll i =0;i<n;i++){
            ll v = sc-c[i]+a[i];
            sai = min(sai, v);
        }
        cout<<sai<<'\n';
    }
}