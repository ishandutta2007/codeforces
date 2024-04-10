#include <bits/stdc++.h>
using namespace std;

int dist(int n) {
  if (!n) return 1;
  if (__builtin_popcount(n)==1) return 0;
  return (1<<(32-__builtin_clz(n)))-n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> counts(n);
    vector<int> pref(1);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      counts[a-1]++;
    }
    for (int i = 0; i < n; i++) {
      if (counts[i]) {
        pref.push_back(pref.back()+counts[i]);
      }
    }

    int ans = 1e9;
    for (int a = 1; a <= n; a *= 2) {
      int x = *(lower_bound(pref.begin(), pref.end(), a+1)-1);
      for (int b = 1; b+x <= n+1; b *= 2) {
        int y = *(lower_bound(pref.begin(), pref.end(), x+b+1)-1);
        ans = min(ans, dist(x)+dist(y-x)+dist(n-y));
      }
    }

    cout << ans << '\n';
  }
}