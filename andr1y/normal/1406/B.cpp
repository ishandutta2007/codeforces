// keep calm and eat pizza.
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
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        ll mr = LLONG_MIN;
        for(ll i = 0;i<=5;i++){
            ll tr=1;
            for(ll j =0;j<i;j++) tr*=a[j];
            for(ll j =0;j<5-i;j++) tr*=a[n-j-1];
            mr=max(mr, tr);
        }
        cout<<mr<<'\n';
    }
}