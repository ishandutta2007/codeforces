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
        ll a, b, n;
        cin >> a >> b >> n;
        if(a<b) swap(a, b);
        if(a>n){
            cout<<0<<'\n';
            continue;
        }
        ll c=0;
        while(a<=n){
            if(a+b>n){
                cout<<c+1<<'\n';
                c=-1;
                break;
            }else{
                b+=a;
                a+=b;
                c+=2;
            }
        }
        if(c!=-1)cout<<c<<'\n';
    }
}