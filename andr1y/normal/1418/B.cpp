// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228;
ll e[N], r[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        vector<ll> a, b;
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) cin >> e[i];
        for(ll i = 0;i<n;i++){
            cin >> r[i];
            if(r[i]) b.push_back(e[i]);
            else a.push_back(e[i]);
        }
        sort(begin(a), end(a), greater<ll>());
        ll pa=0, pb=0;
        for(ll i = 0;i<n;i++){
            if(r[i]) cout<<b[pb++]<<' ';
            else cout<<a[pa++]<<' ';
        }
        cout<<'\n';
	}
}