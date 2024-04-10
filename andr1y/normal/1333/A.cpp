//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                if(j == 0 && i==0) cout << 'W';
                else cout<<'B';
            }
            cout << '\n';
        }
    }
}