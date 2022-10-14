#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int now = m;
    for (int i = 0; i < n; i++) {
        if (a[i] < now) {
            cout << 0 << " ";
            now -= a[i];
            continue;
        }
        cout << 1 + (a[i] - now) / m << " ";
        now = m - ((a[i] - now) % m);
    }
    return 0;
}