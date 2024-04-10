#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
int a[maxn];
ll binpow(ll x, int y, ll mod) {
    ll res = 1;
    while(y > 0) {
        if(y&1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
void solve() {
    cin >> n;
    if(n == 1) {
        cout << "YES\n1\n";
        return;
    }
    if(n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return;
    }
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n1\n";
    for(int i = 2; i < n; i++) {
        cout << binpow(i-1, n-2, n) * i % n << "\n";
    }
    cout << n << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}