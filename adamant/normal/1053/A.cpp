#include <bits/stdc++.h>

using namespace std;

#define int int64_t


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int g1 = __gcd(n, k);
    k /= g1; n /= g1;
    int g2 = __gcd(m, k);
    k /= g2; m /= g2;
    if(k > 2) {
        cout << "NO" << endl;
    } else if(k == 1) {
        if(g1 > 1) {
            cout << "YES" << endl;
            cout << 0 << ' ' << 0 << endl;
            cout << 2 * n << ' ' << 0 << endl;
            cout << 0 << ' ' << m << endl;
        } else if(g2 > 1) {
            cout << "YES" << endl;
            cout << 0 << ' ' << 0 << endl;
            cout << n << ' ' << 0 << endl;
            cout << 0 << ' ' << 2 * m << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "YES" << endl;
        cout << 0 << ' ' << 0 << endl;
        cout << n << ' ' << 0 << endl;
        cout << 0 << ' ' << m << endl;
    }
    
}