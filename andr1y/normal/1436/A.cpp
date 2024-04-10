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
        ll n, m, a,s =0;
        cin >> n >> m;
        for(ll i =0;i<n;i++){
            cin >> a;
            s+=a;
        }
        if(s==m) cout<<"YES\n";
        else cout<<"NO\n";
    }
}