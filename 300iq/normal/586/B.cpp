#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n - 1), b(n - 1);
    vector <int> c(n);
    vector <int> t2, t1;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int sum = 0, cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            sum += b[i];
        }
        cur = sum + c[i];
        for (int j = 0; j < i; j++) {
            cur += a[j];
        }
        t2.push_back(cur);
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            sum += a[i - 1];
        }
        cur = sum + c[i];
        for (int j = i; j < n - 1; j++) {
            cur += b[j];
        }
        t1.push_back(cur);
    }
    reverse(t2.begin(), t2.end());
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ans = min(ans, t1[i] + t2[j]);
            }
        }
    }
    cout << ans << endl;
}