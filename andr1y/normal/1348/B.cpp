//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        set<ll> e;
        for(ll a, i = 0;i<n;i++){
            cin >> a;
            e.insert(a);
        }
        if(e.size()>k) cout << "-1\n";
        else{
            cout << k*n << '\n';
            for(ll i = 0;i<n;i++){
                for(auto j: e) cout << j << ' ';
                for(ll j =0;j<k-e.size();j++) cout << *(e.begin()) << ' ';
            }
            cout << '\n';
        }
    }
}