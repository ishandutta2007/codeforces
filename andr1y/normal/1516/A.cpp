// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
ll lup[N], lc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        ll fn0=0;
        while(fn0<n&&a[fn0]==0) fn0++;
        while(k--&&fn0<n-1){
            ll fc=n-1;
            a[fc]++, a[fn0]--;
            if(a[fn0]==0){
                fn0++;
                while(fn0<n&&a[fn0]==0) fn0++;
            }
        }
        for(ll i = 0;i<n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }
}