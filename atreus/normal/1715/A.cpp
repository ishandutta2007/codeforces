#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 and m == 1) {
        cout << 0 << '\n';
        return;
    }
    cout << (n + m - 2) + min(n, m) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}