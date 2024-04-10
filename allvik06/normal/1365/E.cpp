#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        maxx = max(maxx, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxx = max(maxx, (a[i] | a[j]));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                maxx = max(maxx, (a[i] | a[j] | a[k]));
            }
        }
    }
    cout << maxx;
}