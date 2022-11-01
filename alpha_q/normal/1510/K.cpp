#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005, inf = 1e9;

int a[sz], ara[sz];

int main() {
   int n;
   cin >> n;
   n <<= 1;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), ara[i] = a[i];

   int ans = inf, z = n >> 1;

   for(int k=0; k<=2*n+10; k++) {
      bool yes = 1;
      for(int i=1; i<=n; i++) if(a[i] ^ i) yes = 0;
      if(yes) {
         ans = min(ans, k);
         break;
      }
      if(k & 1) {
         for(int i=1; i<=z; i++) swap(a[i], a[i+z]);
      }
      else {
         for(int i=1; i<=n; i+=2) swap(a[i], a[i+1]);
      }
   }

   for(int i=1; i<=n; i++) a[i] = ara[i];

   for(int k=0; k<=2*n+10; k++) {
      bool yes = 1;
      for(int i=1; i<=n; i++) if(a[i] ^ i) yes = 0;
      if(yes) {
         ans = min(ans, k);
         break;
      }
      if(~k & 1) {
         for(int i=1; i<=z; i++) swap(a[i], a[i+z]);
      }
      else {
         for(int i=1; i<=n; i+=2) swap(a[i], a[i+1]);
      }
   }

   if(ans == inf) ans = -1;
   printf("%d\n", ans);
}