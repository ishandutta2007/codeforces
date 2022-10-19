#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    vector<bool> a;
    cin >> n;

    int last = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      a.push_back(x == last);
      last = x;
    }

    int l = n + 10, r = -1;

    for (int i = 0; i < n; ++i)
      if (a[i]) {
        l = min(l, i);
        r = max(r, i);
      }

    int ans;
    if (r == -1)
      ans = 0;
    else {
      assert(r >= l);
      int len = r - l + 1;
      if (len == 1) {
        ans = 0;
      } else if (len <= 3) {
        ans = 1;
      } else {
        ans = len - 2;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}