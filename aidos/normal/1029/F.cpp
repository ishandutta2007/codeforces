#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
ll a, b;
ll ans;
vector< pair<ll, ll> > v;
void precalc(ll x) {
    for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            v.emplace_back(make_pair(i, x/i));
        }
    }
}
void calc(ll x) {
    auto it = upper_bound(v.begin(), v.end(), make_pair(x, (a+b)/x));
    if(it == v.begin()) return;
    it--;
    if(it->first <= x && it->second <= (a+b)/x) {
        ans = min(ans, x + (a+b)/x);
    }
}
void solve() {
    cin >> a >> b;
    ans = 1ll << 60;
    precalc(a);
    sort(v.begin(), v.end());
    for(ll i = 1; i * i <= a + b; i++) {
        if((a+b) % i == 0) {
            calc(i);
            calc((a+b)/i);
        }
    }
    v.clear();
    precalc(b);
    sort(v.begin(), v.end());
    for(ll i = 1; i * i <= a + b; i++) {
        if((a+b) % i == 0) {
            calc(i);
            calc((a+b)/i);
        }
    }
    cout << 2 * ans << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}