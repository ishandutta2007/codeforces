#include <bits/stdc++.h>

using namespace std;
#define int long long

pair <int, int> f(int a) {
    int b = a;
    int minn = 10, maxx = 0;
    while (b > 0) {
        minn = min(minn, b % 10);
        maxx = max(maxx, b % 10);
        b /= 10;
    }
    return {minn, maxx};
}

signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int t;
     cin >> t;
     while (t--) {
         int a1, k;
         cin >> a1 >> k;
         for (int i = 2; i <= k; ++i) {
             pair <int, int> tmp = f(a1);
             if (tmp.first == 0 || tmp.second == 0) break;
             a1 += tmp.first * tmp.second;
         }
         cout << a1 << "\n";
     }
}