#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0)
        for (int i = 1; i <= n; i += 2)
            cout << i + 1 << ' ' << i << ' ';
    else {
        cout << 1 << ' ';
        for (int i = 2; i <= n; i += 2)
            cout << i + 1 << ' ' << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}