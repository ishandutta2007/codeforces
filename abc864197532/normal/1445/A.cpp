#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1e5, mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        reverse(b, b + n);
        bool is = true;
        for (int i = 0; i < n; ++i) {
            is &= a[i] + b[i] <= x;
        }
        cout << (is ? "Yes\n" : "No\n");
    }
}