//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e5+228;
ll x[N];
ld y[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, r;
    cin >> n >> r;
    cout << fixed << setprecision(7);
    for(ll i = 0;i<n;i++){
        cin >> x[i];
        ld mx = r;
        for(ll j = 0;j<i;j++){
            if(abs(x[i]-x[j])<=(r<<1)){
                ll df = abs(x[i]-x[j]);
                ld hc = sqrt(4*r*r-df*df);
                mx = max(mx, y[j]+hc);
            }
        }
        y[i] = mx;
        cout << y[i] << ' ';
    }
    cout << '\n';
}