// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+1488;
ll mp[N], xs[N], a[N], pf[N], o1[N], o2[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i =1;i<=n;i++){
            cin >> a[i];
            pf[a[i]]=i;
        }
        mp[0]=N;
        for(ll i = 1;i<=n;i++){
            mp[i]=min(mp[i-1], pf[i]);
        }
        xs[n+1]=0;
        for(ll i =n;i>0;i--){
            xs[i]=max(xs[i+1], pf[i]);
        }
        for(ll i = 1;i<=n;i++){
            o1[i]=o1[i-1];
            if(mp[i-1]<pf[i]) o1[i]++;
        }
        for(ll i = 1;i<=n;i++){
            o2[i]=o2[i-1];
            if(xs[i+1]>pf[i]) o2[i]++;
        }
        bool ok=0;
        for(ll i = 1;i<=n&&!ok;i++){
            if(o1[n]-o1[i]==n-i&&o2[i-1]==i-1) ok=1;
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}