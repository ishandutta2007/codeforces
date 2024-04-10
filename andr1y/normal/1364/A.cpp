// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll a[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        ll sum = 0, mx=-1, fc=-1;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            if(fc==-1&&a[i]%x) fc=i;
            ll ln = (sum%x?i+1:(fc==-1?-1:i-fc));
            mx=max(mx, ln);
        }
        cout<<mx<<'\n';
    }
}