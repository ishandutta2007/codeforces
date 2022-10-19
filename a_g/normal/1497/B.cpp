#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      counts[val % m]++;
    }
    int ans = 0;
    for (int res = 0; res <= m/2; res++) {
      int complement = m-res;
      if ((res-complement) % m == 0) {
        if (counts[res]) ans++;
      }
      else {
        int val1 = counts[res];
        int val2 = counts[complement];
        int diff = abs(val1-val2);
        if (diff > 0) {
          ans += diff;
        }
        else {
          if (val1) ans++;
        }
      }
    }
    cout << ans << endl;
  }
}