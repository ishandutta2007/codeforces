#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = 998244353;
int n, m;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll d = k+y*k;
    cout << (d-1 + (x-2))/(x-1) + k << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}