//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
ll mlg(ll n){
    ll c = 0;
    while(n){
        ++c, n>>=1;
    }
    return c-1;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, mv = -1;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(i){
                ll df = a[i-1]-a[i];
                if(df>0) mv = max(mv, mlg(df)), a[i] = a[i-1];
            }
        }
        cout << mv+1 << '\n';
    }
}