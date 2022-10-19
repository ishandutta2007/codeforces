#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    map <int, int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]] = i + 1;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a.size() < k) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < k; ++i) {
            cout << b[a[i]] << " ";
        }
    }
}