#include <bits/stdc++.h>

using namespace std;
#define int long long
int mod = 998244353;
signed main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    if (n > m) {
        for (int i = 0; i < n - m; ++i) {
            b += '0';
        }
    }
    else if (m > n) {
        for (int i = 0; i < m - n; ++i) {
            a += '0';
        }
    }
    string tmpa, tmpb;
    cin >> tmpa >> tmpb;
    a = a + tmpa;
    b = b + tmpb;
    m = n = max(n, m);
    vector <int> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (b[i] == '1');
    }
    vector <int> two(n);
    two[0] = 1;
    for (int i = 1; i < n; ++i) {
        two[i] = two[i - 1] * 2 % mod;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            continue;
        }
        int bi = n - i - 1;
        ans += two[bi] * pref[i + 1];
        ans %= mod;
    }
    cout << ans;
    return 0;
}