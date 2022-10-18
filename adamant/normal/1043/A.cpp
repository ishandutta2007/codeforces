#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

const int maxn = 1e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    for(int k = mx; k <= 3 * mx; k++) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum1 += a[i];
            sum2 += k - a[i];
        }
        if(sum2 > sum1) {
            cout << k << endl;
            return 0;
        }
    }
    return 0;
}