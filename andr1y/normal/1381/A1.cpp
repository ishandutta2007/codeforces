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
        string a, b;
        cin >> n >> a >> b;
        vector<ll> r;
        for(ll i = n-1;i>=0;i--){
            char f = a[0], t = b[i];
            if(f!=t){
                r.push_back(i+1);
                string a2=a;
                for(ll j = 0;j<=i;j++){
                    a2[j] = (a[i-j]=='0'?'1':'0');
                }
                a=a2;
            }else{
                r.push_back(1);
                a[0]=(a[0]=='1'?'0':'1');
                r.push_back(i+1);
                string a2=a;
                for(ll j = 0;j<=i;j++){
                    a2[j] = (a[i-j]=='0'?'1':'0');
                }
                a=a2;
            }
        }
        cout << r.size()<<' ';
        for(auto i : r) cout<<i<<' ';
        cout<<'\n';
    }
}