#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;

ll n, m, k;
void solve() {
    cin >> n >> m >> k;
    if(n * m - 1 == k) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}