#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b(n, -1);
    set<int> c;
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            c.insert(a[i - 1]);
        }
    if (a[0] == 1) {
        b[0] = 0;
        c.insert(0);
    }
    c.insert(a[n - 1]);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1)
            continue;
        while (c.count(k) != 0) 
            k++;
        b[i] = k;
        k++;
    }
    for (int i = 0; i < n; ++i)
        cout << b[i] << ' ';
    return 0;
}