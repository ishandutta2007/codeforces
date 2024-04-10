
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
int n, m, k;

void solve() {
    int x;
    cin >> x;
    int cur = 1;
    ll le = 0, ri = 0;
    while(x < le || x > ri || abs(x % 2) != abs(ri) % 2) {
        le -= cur;
        ri += cur;
        cur++;
    }
    cout << (cur-1) << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}