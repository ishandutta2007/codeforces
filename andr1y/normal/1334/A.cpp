//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228;
ll a[N], b[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        bool ok = 1;
        for(ll i =0;i<n;i++){
            cin >> a[i] >> b[i];
            ok = ok && a[i]>=b[i];
            if(i) ok = ok && a[i]>=a[i-1] && b[i] >= b[i-1] && a[i]-a[i-1]>=b[i]-b[i-1];
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}