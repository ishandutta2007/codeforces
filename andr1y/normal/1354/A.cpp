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
        ll a, b, c, d;
        cin >> a >> b >> c>>d;
        if(a<=b){
            cout<<b<<'\n';
        }else{
            ll u = c-d;
            if(u<=0) cout << "-1\n";
            else{
                ll e = a-b;
                ll v = e/u+(e%u?1:0);
                cout << b+c*v << '\n';
            }
        }
    }
}