#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sum = 0;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    if (sum % 3 != 0)
        return 0 * puts("0");
    vector <int> points(n);
    long long res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += a[i];
        points[i] = (res == sum / 3);
    }
    vector <int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ans[i] = points[i];
        }
        else {
            ans[i] = ans[i + 1] + points[i];
        }
    }
    res = 0;
    long long f = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
        if (res == sum / 3 && i + 2 < n) {
            f += ans[i + 2];
        }
    }
    cout << f << endl;
}