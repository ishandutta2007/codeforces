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
        ll l, r;
        cin >> l >> r;
        if(l*2>r) cout<<"-1 -1\n";
        else cout<<l << ' ' << l+l<<'\n';
    }
}