#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                sum += a[i];
            else
                sum -= a[i];
        }
        if (sum % 360 == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}