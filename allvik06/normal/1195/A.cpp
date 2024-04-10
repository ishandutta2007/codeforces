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
    int n, k, q, res = 0, res1 = 0;
    cin >> n >> k;
    vector <int> a(k);
    for (int i = 0; i < n; i++) {
        cin >> q;
        a[q - 1] += 1;
    }
    for (int i = 0; i < k; i++) {
        if (a[i] >= 2) {
            if (a[i] % 2 == 0) {
                res += a[i];
                a[i] = 0;
            }
            else {
                res += a[i] - 1;
                a[i] = 1;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        res1 += a[i];
    }
    res += (int) (res1 + 1) / 2;
    cout << res;
}