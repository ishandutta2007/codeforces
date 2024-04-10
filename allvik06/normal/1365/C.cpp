#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <int> sk(n);
    vector <int> g(n + 1);
    for (int i = 0; i < n; ++i) {
        g[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (i <= g[a[i]]) {
            ++sk[g[a[i]] - i];
        }
        else {
            ++sk[n - i + g[a[i]]];
        }
    }
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        maxx = max(maxx, sk[i]);
    }
    cout << maxx;
}