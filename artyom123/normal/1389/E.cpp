#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define fi first
#define se second
#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll m, d, w;
        cin >> m >> d >> w;
        m = min(m, d);
        w /= __gcd(w, d - 1);
        cout << w * (m / w) * (m / w - 1) / 2 + (m % w) * (m / w) << "\n";
    }
    return 0;
}