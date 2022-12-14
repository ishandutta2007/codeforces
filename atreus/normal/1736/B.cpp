#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    a[1] = b[1];
    for (int i = 2; i <= n; i++)
        a[i] = lcm(b[i - 1], b[i]);
    a[n + 1] = b[n];
    for (int i = 1; i <= n; i++)
        if (gcd(a[i], a[i + 1]) != b[i]) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}