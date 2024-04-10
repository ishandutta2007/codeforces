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
        ll n, r, v=0;
        cin >> n >> r;
        if(r>=n) v=1;
        r=min(n-1, r);
        v += (r*(r+1))>>1;
        cout<<v<<'\n';
    }
}