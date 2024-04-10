#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 1e5 + 42;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > mx) {
            cout << i + 1 << endl;
            return 0;
        }
        mx = max(mx, a[i] + 1);
    }
    cout << -1 << endl;
    return 0;
}