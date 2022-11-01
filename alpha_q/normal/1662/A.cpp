#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n;
   cin >> n;
   int a[11] = {};
   for(int i=0; i<n; i++) {
      int b, d;
      scanf("%d %d", &b, &d);
      a[d] = max(a[d], b);
   }
   int sum = 0;
   for(int i=1; i<11; i++) {
      if(!a[i]) {
         puts("MOREPROBLEMS");
         return;
      }
      sum += a[i];
   }
   printf("%d\n", sum);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}