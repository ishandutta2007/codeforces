#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int c[sz], shop[sz];

int main() {
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) scanf("%d", &c[i]);
   for(int i=0; i<m; i++) scanf("%d", &shop[i]);

   sort(shop, shop + m);

   map <ll,ll> mp;
   for(int i=0; i<n; i++) {
      ll x = i * 100;
      int j = lower_bound(shop, shop + m, x) - shop;
      ll d = INT_MAX;
      if(j < m) d = min(d, shop[j] - x);
      j--;
      if(j >= 0) d = min(d, x - shop[j]);
      if(!d) continue;
      x <<= 1, d <<= 1;
      mp[x - d + 1] += c[i];
      mp[x + d] -= c[i];
   }

   ll sum = 0, ans = 0;
   for(auto [x, g] : mp) {
      sum += g;
      ans = max(ans, sum);
   }
   cout << ans;
}