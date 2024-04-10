// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        set<ll, greater<ll>> st;
        for(ll i = 1;i<=n;i++) st.insert(i);
        vector<pair<ll, ll>> e;
        for(ll i = 1;i<n;i++){
            ll a = *st.begin();st.erase(st.begin());
            ll b = *st.begin();st.erase(st.begin());
            ll c = (a+b+1)/2;
            st.insert(c);
            e.push_back({a, b});
        }
        cout<<*st.begin()<<'\n';
        for(auto i : e) cout<<i.first<<' '<<i.second<<'\n';
    }
}