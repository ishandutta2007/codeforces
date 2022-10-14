#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n;) {
        int p = a[i];
        int now = 0;
        while (i < n && a[i] <= p * 2) {
            p = a[i];
            i++;
            now++;
        }
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}