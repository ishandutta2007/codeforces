// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1e5+228;
const ld EPS = 0.000000001;
ll a[N];
ld time_to[N], tt2[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        a[0]=0;
        for(ll i = 1;i<=n;i++){
            cin >> a[i];
            time_to[i] = time_to[i-1]+((ld)(a[i]-a[i-1]))/((ld)i);
        }
        a[n+1]=x;
        tt2[n+1]=0;
        for(ll i = n, j=1;i>0;i--, j++){
            tt2[i] = tt2[i+1]+((ld)(a[i+1]-a[i]))/((ld)j);
        }
        ld l = 1, r = 1e9;
        while(r-l>EPS){
            ld m = (l+r)/2;
            ll sk1 = 0;
            for(ll i = 1;i<=n;i++){
                if(time_to[i]-m<EPS) sk1 = i;
            }
            ll sk2=n+1;
            for(ll i = n;i>0;i--){
                if(tt2[i]-m<EPS) sk2=i;
            }
            ld tk1 = time_to[sk1];
            ld tk2 = tt2[sk2];
            ld lk1 = m-tk1;
            ld lk2 = m-tk2;
            ll v1 = sk1+1, v2 = (n-sk2)+2;
            ld lpx = a[sk1] + v1*lk1;
            ld lpy = a[sk2] - v2*lk2;
            if(lpx-lpy<EPS) l=m;
            else r=m;
        }
        ld m = l;
        cout<<fixed<<setprecision(10)<<m<<'\n';
    }
}