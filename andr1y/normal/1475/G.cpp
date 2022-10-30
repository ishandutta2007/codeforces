// -- //
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N = 200002;
ll a[N], b[N], z[N];
inline void cmax(ll &a, ll &b){
    if(b>a) a=b;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll qe;
    cin >> qe;
    for(ll q=1;q<=qe;q++){
        ll n;
        cin >> n;
        for(ll c, i=0;i<n;i++){cin>>c;if(z[c]==q) a[c]++; else a[c]=1, z[c]=q;}
        for(ll i = N-1;i;i--){
            if(z[i]!=q) a[i]=0;
            ll e = 0;
            for(ll k=i+i;k<N;k+=i) cmax(e, b[k]);
            b[i]=a[i]+e;
        }
        cout<<n-b[1]<<'\n';
    }
}