#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int size = 2 * k + 3;
        vector <int> nul(size), one(size);
        for (int i = 0; i < n / 2; ++i) {
            ++nul[a[i] + a[n - i - 1]];
            ++one[min(a[i], a[n - i - 1]) + 1];
            --one[a[i] + a[n - i - 1]];
            ++one[a[i] + a[n - i - 1] + 1];
            --one[max(a[i], a[n - i - 1]) + k + 1];
        }
        for (int i = 1; i < size; ++i) {
            one[i] = one[i - 1] + one[i];
        }
        int minn = n;
        for (int i = 1; i <= 2 * k; ++i) {
            minn = min(minn, one[i] + (n / 2 - one[i] - nul[i]) * 2);
        }
        cout << minn << "\n";
    }
}