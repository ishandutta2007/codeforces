// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) cin >> a[i];
        ll tm = a[0], bm = 0;
        bool ok =1;
        for(ll i = 0;i<n;i++){
            tm=min(tm, a[i]);
            b[i]=a[i]-tm;
            bm=max(bm, b[i]);
            if(bm>a[i]) ok=0;
            else tm=min(tm, a[i]-bm);
        }
        //for(ll i = 1;i<n;i++) b[i]=max(b[i], b[i-1]);

        //for(ll i = 0;i<n;i++) ok=ok&&(b[i]<=a[i]);
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}