// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll se=0, so=0, me=inf, mo=inf, co=0, ce=0;
        ll res = inf;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(i&1){
                so+=a[i];
                co++;
                mo=min(mo, a[i]);
            }else{
                se+=a[i];
                ce++;
                me=min(me, a[i]);
            }
            if(i==0) continue;
            ll rets = se + (n-ce)*me + so + (n-co)*mo;
            res=min(res, rets);
        }
        cout<<res<<'\n';
    }
}