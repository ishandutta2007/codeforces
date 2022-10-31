//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
bool a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) a[i]=0;
        bool ok = 1;
        for(ll b, i = 0;i<n;i++) {
            cin >> b;
            ll bb = b%n;
            if(bb<0) bb+=n;
            ll md = (i+bb)%n;
            if(a[md]) ok = 0;
            else a[md]=1;
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
}