#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

signed main() {
    const int MOD = 998244353;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 1;
    while (s[l] == s[0]) {
        l++;
    }
    int r = 1;
    while (s[n - 1 - r] == s[n - 1]) {
        r++;
    }
    if (s[0] == s[n - 1]) {
        cout << (ll) (r + 1) * (l + 1) % MOD;
    } else {
        cout << l + r + 1 << endl;
    }
    return 0;
}