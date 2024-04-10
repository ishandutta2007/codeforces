#include <bits/stdc++.h>

using ll = long long;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << w1 * 2 + (h1 + h2) * 2 + 4;
}