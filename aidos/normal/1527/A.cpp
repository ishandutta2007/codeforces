#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
void solve() {
    cin >> n;
    ll cur = 1;
    while(cur < n) {
        cur *= 2;
        cur++;
    }
    cout << cur/2 << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}