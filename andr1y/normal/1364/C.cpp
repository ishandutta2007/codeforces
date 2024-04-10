// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll rs[N], a[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        rs[i]=-1;
        cin >> a[i];
    }
    for(ll i = 1;i<n;i++){
        if(a[i]!=a[i-1]) rs[i]=a[i-1];
    }
    stack<ll> frees;
    ll fn=1, fs=0, ok=1;
    if(a[0]==1) rs[0]=0;
    while(fs<n){
        while(fn<n&&a[fn]==a[fs])fn++;
        ll from = a[fs], to=a[fn]-1, p=fs+(rs[fs]==-1?0:1);
        while(to>from&&p<fn){
            rs[p++]=to--;
        }
        while(to>from&&frees.size()>0){
            rs[frees.top()]=to--;
            frees.pop();
        }
        if(to>from){
            ok=0;
            break;
        }
        while(p<fn) frees.push(p++);
        fs=fn++;
    }
    while(frees.size()){
        rs[frees.top()]=1e6;
        frees.pop();
    }
    if(ok){
        for(ll i = 0;i<n;i++) cout<<rs[i]<<' ';
    }else cout<<-1;
}