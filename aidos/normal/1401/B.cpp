#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    ll x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    ll x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    ll c = min(x1, z2);
    x1 -= c;
    z2 -= c;
    ll ans = 0;
    c = min(z1, y2);
    z1 -= c;
    y2 -= c;
    ans += c * 2;
    ll a = y1;
    ll b = x1 + z1;
    ll e = z2;
    ll f = x2 + y2;
    if(b < e) {
        ans -= (e-b) * 2;
    }
    cout<< ans<<"\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}