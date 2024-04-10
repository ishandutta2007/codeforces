#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i]);
    int mx = *max_element(a, a + n);
    cout << mx / g << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}