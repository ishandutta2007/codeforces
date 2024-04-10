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
        ll n, k;
        cin >> n >> k;
        vector<ll> res;
        for(ll i = k+1;i<=n;i++) res.push_back(i);
        for(ll i=k-1;i+i>=k;i--) res.push_back(i);
        cout<<res.size()<<'\n';
        for(auto i : res) cout<<i<<' ';
        cout<<'\n';
    }
}