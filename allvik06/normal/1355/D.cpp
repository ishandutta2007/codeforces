#include <bits/stdc++.h>

using namespace std;

signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n, s;
     cin >> n >> s;
     if (2 * n > s) {
         cout << "NO\n";
     }
     else {
         cout << "YES\n";
         for (int i = 0; i < n - 1; ++i) {
             cout << 2 << " ";
         }
         cout << s - 2 * (n - 1) << "\n";
         cout << 1 << "\n";
     }
}