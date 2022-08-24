#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef unsigned long long ll;

mt19937 rnd(228);

int main() {
   int t;
   cin >> t;
   while (t--) {
       int n, z;
       cin >> n >> z;
       int ans = 0;
       for (int i = 0; i < n; i++) {
           int x;
           cin >> x;
           ans = max(ans, x | z);
       }
       cout << ans << '\n';
   }
}