// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        set<ll> s;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            for(ll j = i-1;j>=0;j--){
                s.insert(a[i]-a[j]);
            }
        }
        cout<<s.size()<<'\n';
    }
}