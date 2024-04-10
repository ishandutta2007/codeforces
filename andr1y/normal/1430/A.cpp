// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        bool f=0;
        for(ll tr=0;tr+tr+tr<=n&&!f;tr++){
            ll k = n-tr-tr-tr;
            for(ll pt=0;pt*5<=k;pt++){
                ll e = k-pt*5;
                if(e%7==0){
                    cout<<tr<<' '<<pt<<' '<<e/7<<'\n';
                    f=1;
                    break;
                }
            }
        }
        if(!f) cout<<"-1\n";
    }
}