#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
void solve() {
    cin >> n;
    vector<int> p;
    m = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n/=i;
            }
            p.emplace_back(i);
        }
    }
    if(n > 1) p.emplace_back(n);
    if(p.size() < 2) {
        cout << "NO\n";
        return;
    }
    int x = 1;
    int y = m;
    while(y % p[0] == 0) {
        y /= p[0];
        x *= p[0];
    }
    if(y < x) swap(x, y);
    for(int i = 0; i < x; i++) {
        //i/x + j/y  = (m-1)/m
        //i * y + j * x = m - 1
        int cur = m - 1 - i * y;
        if(cur >= 0 && cur % x == 0 && cur / x < y) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << i << " " << x << "\n";
            cout << cur/x << " " << y << "\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}