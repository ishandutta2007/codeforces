#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef unsigned long long ll;

mt19937 rnd(228);

int main() {
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       int ans = 0;
       int last = -2;
       for (int i = 0; i < n; i++) {
           int x;
           cin >> x;
           if (x != 0) {
               if (last != i - 1) {
                   ans++;
               }
               last = i;
           }
       }
       cout << min(2, ans) << '\n';
   }
}