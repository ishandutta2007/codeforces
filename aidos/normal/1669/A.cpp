
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e4 + 10;
int n, m;

void solve() {
    cin >> n;
    if(n < 1400) {
        cout << "Division 4\n";
    } else if(n < 1600) {
        cout << "Division 3\n";
    } else if(n < 1900) {
        cout << "Division 2\n";
    } else {
        cout << "Division 1\n";
    }
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