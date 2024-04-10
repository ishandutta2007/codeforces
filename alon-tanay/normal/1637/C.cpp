#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t --) {
        ll n;
        cin >> n;
        ll total = 0;
        ll x;
        ll val = 0;
        ll even = 0;
        ll mx = 0;
        ll nonzero = 0;
        cin >> x;
        for(ll i = 2; i < n; i ++) {
            cin >> x;
            total += (x+1)/2;
            if(x & 1) {
                val ++;
            }
            if(x) {
                nonzero ++;
            }
            mx = max(mx, x);
        }
        cin >> x;
        if(mx == 1 || (val == 1 && nonzero == 1)) {
            cout << "-1\n";
            continue;
        }
        cout << total << "\n";
    }
    return 0;
}