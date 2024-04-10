// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, ss=0, mx=0;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            ss+=a[i];
            mx=max(mx, a[i]);
        }
        ll k = max((ss+n-2)/(n-1), mx);
        cout<<k*(n-1)-ss<<'\n';
    }
}