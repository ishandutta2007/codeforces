#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
int n, m, s;
ll p;
ll a[3];
void solve() {
    cin >> p;
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
        a[i] = (a[i] + p - 1)/a[i] * a[i];
    }
    cout << *min_element(a, a + 3) - p << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}