#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int min = 1e14;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] -= i;
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] - min / n * n;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] <= n) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}