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
         int n;
         cin >> n;
         vector <int> a(n);
         for (int i = 0; i < n; ++i) cin >> a[i];
         int ans = 0, kol = 0;
         sort(a.begin(), a.end());
         for (int i = 0; i < n; ++i) {
             if (kol + 1 >= a[i]) {
                 ++ans;
                 kol = 0;
             }
             else {
                 ++kol;
             }
         }
         cout << ans << "\n";
     }
}