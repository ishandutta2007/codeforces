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
        for(ll i = 0;i<n;i++) cin >> a[i];
        ll minr=k+a[0], maxr=k+a[0];
        bool ok = 1;
        for(ll i = 1;i+1<n&&ok;i++){
            ll g0 = a[i]+k, g1 = a[i]+k+k-1;
            ll b0 = minr-k+1, b1 = maxr+k-1;
            minr=max(g0, b0);
            maxr=min(g1, b1);
            if(minr>maxr) ok=0;
        }
        if(ok&&a[n-1]+k>minr-k&&a[n-1]<maxr) cout<<"yes\n";
        else cout<<"no\n";
    }
}