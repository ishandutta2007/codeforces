#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x, f;
    cin >> x >> f;
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= x) {
            break;
        }
        ans += (a[i] - x + x + f - 1) / (x + f);
    }
    cout << ans * f;
    return 0;
}