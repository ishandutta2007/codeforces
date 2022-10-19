#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p >= l && p <= r) a.push_back(p);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int total = 0;
    while (ans < a.size() && total+a[ans] <= k) {
      total += a[ans];
      ans++;
    }
    cout << ans << '\n';
  }
}