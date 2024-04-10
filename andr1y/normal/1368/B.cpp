// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll c[10];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i  =0;i<10;i++)c[i]=1;
    ll v=1;
    ll pos=0;
    while(v<n){
        v/=c[pos];
        c[pos]++;
        v*=c[pos];
        pos++;
        if(pos==10)pos=0;
    }
    string ee="codeforces";
    for(ll i = 0;i<10;i++){
        while(c[i]--) cout<<ee[i];
    }
}