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
        ll n, a, t=0;
        cin >> n;
        while(n--){
            cin >> a;
            a=abs(a);
            if(t) a=-a;
            cout<<a<<' ';
            t^=1;
        }
        cout<<'\n';
    }
}