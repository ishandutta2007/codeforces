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
        ll n;
        cin >> n;
        for(ll i =0;i<n;i++)cin >> a[i];
        bool w1 = 0, wm1 = 0, ok = 1;
        for(ll i=0;i<n;i++){
            ll k;
            cin >> k;
            if(k>a[i]) ok = ok && w1;
            if(k<a[i]) ok = ok && wm1;
            if(a[i] == -1) wm1 = 1;
            if(a[i] == 1) w1 = 1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}