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
        ll a, b, n, m;
        cin >>a >> b >> n >> m;
        if(m<=min(a, b)&&n+m<=a+b) cout<<"Yes\n";
        else cout<<"No\n";
    }
}