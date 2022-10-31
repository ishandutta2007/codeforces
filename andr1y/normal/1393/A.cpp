// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(n&1){
            ll a = n-(n/2);
            cout<<a<<'\n';
        }else{
            ll a = n-((n/2)-1);
            cout<<a<<'\n';
        }
    }
}