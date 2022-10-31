// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
ll a[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) cin >> a[i];
        vector<ll> ans;
        ans.push_back(a[0]);
        for(ll i = 1;i<n;i++){
            if(ans.size()<2){
                ans.push_back(a[i]);
            }else if((a[i]-ans[ans.size()-1]<0)==(ans[ans.size()-1]-ans[ans.size()-2]<0)){
                ans[ans.size()-1] = a[i];
            }else{
                ans.push_back(a[i]);
            }
        }
        cout<<ans.size()<<'\n';
        for(auto i : ans) cout<< i << ' ';
        cout<<'\n';
    }
}