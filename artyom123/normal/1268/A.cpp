#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string s = a;
    for (int i = 0; i < n; i++) {
        if (i + k >= n) {
            continue;
        }
        a[i + k] = a[i];
    }
    if (a >= s) {
        cout << n << "\n" << a;
        return 0;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < '9') {
            a[i]++;
            for (int j = i + 1; j < k; j++) {
                a[j] = '0';
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i + k >= n) {
            continue;
        }
        a[i + k] = a[i];
    }
    cout << n << "\n" << a;
    return 0;
}