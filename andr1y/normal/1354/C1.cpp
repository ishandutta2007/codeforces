//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e5+228;
const ld PI = 3.1415926535897932384626433832795;
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ld ans = 1;
        ld u2 = tan(PI/(2*n));
        ans/=u2;
        cout << fixed << setprecision(10) << ans << '\n';
    }
}