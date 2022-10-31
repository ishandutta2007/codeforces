// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        ++k;
        sort(a, a+n, greater<ll>());
        ll res=0;
        for(ll i = 0;i<k;i++) res+=a[i];
        cout<<res<<'\n';
    }
}