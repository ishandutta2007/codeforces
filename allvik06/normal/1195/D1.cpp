#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

const int INF = 1e18;

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int u = 1;
        while (a[i] != 0) {
            res += ((a[i] % 10) * u * n) % 998244353;
            u *= 10;
            u %= 998244353;
            res += ((a[i] % 10) * u * n) % 998244353;
            a[i] /= 10;
            u *= 10;
            u %= 998244353;
            res = res % 998244353;
        }
    }
    cout << res;
}