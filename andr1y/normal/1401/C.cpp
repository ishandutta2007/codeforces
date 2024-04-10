#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], fxd[N], ufx[N], ufxc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll n;
        cin >> n;
        ufxc=0;
        ll mn = LLONG_MAX;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            fxd[i]=0;
            mn=min(mn, a[i]);
        }
        bool ok=1;
        for(ll i = 1;i<n;i++) ok=ok&&a[i]>=a[i-1];
        if(ok){
            cout<<"YES\n";
            continue;
        }
        ll g=0;
        for(ll i = 0;i<n;i++){
            if(a[i]%mn==0){
                ufx[ufxc++] = a[i]/mn;
                g=__gcd(g, a[i]/mn);
            }else fxd[i]=a[i];
        }
        if(g==1){
            sort(ufx, ufx+ufxc);
            ll e=0;
            for(ll i = 0;i<n;i++){
                if(fxd[i]) continue;
                fxd[i]=mn*ufx[e++];
            }
            bool ok=1;
            for(ll i = 1;i<n;i++) ok=ok&&fxd[i]>=fxd[i-1];
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            cout<<"NO\n";
        }
	}
}