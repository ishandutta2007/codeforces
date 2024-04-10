#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        for (int i = max(0LL, n - 64); i < n; i++) {
            for (int j = i; j < n; j++) {
                if (max(1LL, 1LL << (n - j - 2)) > k) {
                    reverse(arr.begin() + i, arr.begin() + j + 1);
                    i = j;
                    break;
                }
                k -= (1LL << (n - j - 2));
            }
        }
        if (k != 0) {
            cout << -1 << endl;
            continue;
        }
        for (int el : arr) {
            cout << el << ' ';
        }
        cout << endl;
    }
}