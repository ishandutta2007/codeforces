#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        vector<int> a(n);
        int d = 0;
        for (int i = 0; i < n / 2; i += 2) {
            a[i] = 2 + d;
            a[i + 1] = 6 + d;
            a[i + n / 2] = 3 + d;
            a[i + 1 + n / 2] = 5 + d;
            d = a[i + 1];
        }
        for (auto &c : a) {
            cout << c << " ";
        }
        cout << "\n";
    }
    return 0;
}