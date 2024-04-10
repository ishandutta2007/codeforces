// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 128;
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        for(ll i = 1;i<n;i+=2){
            b[i] = -a[i-1];
            b[i-1] = a[i];
        }
        for(ll i = 0;i<n;i++) cout<<b[i]<<  ' ';
        cout<<'\n';
    }
}