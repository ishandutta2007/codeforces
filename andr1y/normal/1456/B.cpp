// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    for(ll i  =0;i<n;i++){
        if(i&&((i>1&&(a[i]^a[i-1])<a[i-2])||(i+1<n&&(a[i]^a[i-1])>a[i+1]))){
            cout<<1;
            return 0;
        }
        b[i]=a[i];
        if(i) b[i]^=b[i-1];
    }
    ll res=n+n;
    for(ll i = 0;i<n;i++){
        ll lf=0, rg=0;
        for(ll j = i;j>=0;j--){
            lf^=a[j], rg=0;
            for(ll k = i+1;k<n;k++){
                rg^=a[k];
                if(lf>rg){
                    res=min(res, i-j+k-i-1);
                }
            }
        }
    }
    if(res==n+n) cout<<-1;
    else cout<<res;
}