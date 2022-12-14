#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    ll sum = 0;
    ld ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        sum += a[i];
        if(i <= m) {
            ans = max(ans, (sum + min(k * (n - i), m - i)) / (ld)(n - i));
        }
    }
    
    cout.precision(228);
    cout << ans << endl;
}