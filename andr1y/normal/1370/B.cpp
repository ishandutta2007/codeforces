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
        stack<ll> a0, a1;
        cin >> n;
        for(ll a, i=0;i<n+n;i++){
            cin >> a;
            if(a&1) a1.push(i);
            else a0.push(i);
        }
        if(a1.size()&1){
            a0.pop(), a1.pop();
        }else{
            if(!a0.empty()){
                a0.pop();
                a0.pop();
            }else{
                a1.pop();
                a1.pop();
            }
        }
        while(!a0.empty()){
            cout<<a0.top()+1<<' ';
            a0.pop();
            cout<<a0.top()+1<<'\n';
            a0.pop();
        }
        while(!a1.empty()){
            cout<<a1.top()+1<<' ';
            a1.pop();
            cout<<a1.top()+1<<'\n';
            a1.pop();
        }
    }
}