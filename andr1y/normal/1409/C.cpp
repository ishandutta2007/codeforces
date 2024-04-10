// keep calm and eat pizza.
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
        ll n, x, y;
        cin >> n >> x >> y;
        ll mnx=LLONG_MAX, mnv=0, mn2=0;
        for(ll btw=0;x+btw<y&&2+btw<=n;btw++){
            if((y-x)%(btw+1)) continue;
            ll d = (y-x)/(btw+1);
            for(ll px=0;px+btw+1<n;px++){
                bool ok = 1;
                for(ll i = 0;i<n&&ok;i++){
                    a[i] = x+d*(i-px);
                    if(a[i]<=0){
                        ok=0;
                    }
                }
                if(ok&&a[n-1]<mnx){
                    mnx=a[n-1];
                    mnv = btw, mn2 = px;
                }
            }
        }
        ll d = (y-x)/(mnv+1);
        for(ll i = 0;i<n;i++){
            a[i] = x+d*(i-mn2);
        }
        for(ll i = 0;i<n;i++) cout<<a[i]<<' ';
        cout<<'\n';
	}
}