#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >>t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        while(max(a, b) <= n) {
            ll x = max(a, b);
            ll y = a + b;
            a = x;
            b=  y;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}