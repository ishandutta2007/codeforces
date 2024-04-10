// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+1488;
ll a[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    ll n = s.length();
    for(ll i = 0;i<n;i++){
        if(s[i]=='(') a[i]++;
        else a[i]--;
    }
    stack<ll> sps;
    ll mv=0, mc=1, lub=-1;
    for(ll i = 0;i<n;i++){
        if(s[i]=='('){
            sps.push(i);
        }else{
            if(!sps.empty()){
                sps.pop();
                ll vv=0;
                if(!sps.empty()){
                    vv = i-sps.top();
                }else{
                    vv=i-lub;
                }
                if(vv>mv) mv=vv, mc=0;
                if(vv==mv) mc++;
            }else{
                lub=i;
            }
        }
    }
    cout<<mv<<' ' << mc<<'\n';
}