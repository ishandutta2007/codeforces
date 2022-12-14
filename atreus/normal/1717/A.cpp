#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int c[maxn], p[maxn];

void solve() {
    int n;
    cin >> n;
    cout << n + 2 * (n / 2) + 2 * (n / 3) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}