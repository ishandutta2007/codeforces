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
    int n, k, l = 0, r = 1e9, m;
    cin >> n >> k;
    while (l != r - 1) {
        m = (l + r) / 2;
        if (m * (m + 1) / 2 - n + m == k) {
            cout << n - m;
            exit(0);
        }
        if (m * (m + 1) / 2 - n + m > k) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << n - m;
}