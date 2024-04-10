#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a)
            cin >> e;
        sort(a.begin(), a.end());
        long long sum = 0;
        for (int i = 0; i < n; i++) 
            sum += a[i];
        long long pref = 0;
        double mx = -3e9;        
        for (int i = 0; i + 1 < n; i++) {
            pref += a[i];
            double avg = 1.0 * pref / (i + 1) + 1.0 * (sum - pref) / (n - i - 1);
            mx = max(mx, avg);
        }
        cout << setprecision(10) << fixed << mx << '\n';
    }

    return 0;
}