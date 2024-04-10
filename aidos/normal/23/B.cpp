
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 10;
int n, m, k;

void solve() {
    cin >> n;
    if(n <= 2) {
        cout<<0<<"\n";
    } else {
        cout << n - 2 << "\n";
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