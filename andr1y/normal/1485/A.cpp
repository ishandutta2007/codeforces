// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll bpm(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return a*bpm(a*a, b>>1);
    else return bpm(a*a, b>>1);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        ll off=0;
        if(b==1) b=2, off=1;
        ll mr=max(0ll, a-b+1)+1;
        for(ll i = 1;i<=35;i++){
            for(ll upb=0;upb<=i;upb++){
                ll nb = b+upb;
                ll na=a;
                for(ll tc=0;tc<i-upb;tc++) na/=nb;
                if(na==0) mr=min(mr, i);
            }
        }
        cout<<mr+off<<'\n';
    }
}