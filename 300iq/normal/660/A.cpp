#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        res.push_back(a[i]);
        if (__gcd(a[i], a[i + 1]) != 1) {
            ans++;
            res.push_back(1);
        }
    }
    res.push_back(a[n - 1]);
    cout << ans << endl;
    for (int i = 0; i < (int) res.size(); i++) {
        cout << res[i] << " ";
    }
}