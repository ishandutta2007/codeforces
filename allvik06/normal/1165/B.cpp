#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    multiset <int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 1; i <= n; ++i) {
        while (!a.empty() && *a.begin() < i) a.erase(a.begin());
        if (a.empty()) {
            cout << i - 1;
            return 0;
        }
        a.erase(a.begin());
    }
    cout << n;
}