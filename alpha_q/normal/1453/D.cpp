#include <bits/stdc++.h>

using namespace std;

int t;
long long k;

int main() {
  cin >> t;
  while (t--) {
    cin >> k;
    if (k & 1) {
      puts("-1");
      continue;
    }
    k >>= 1;
    vector <int> ans;
    while (k) {
      int len = 1;
      long long cur = 1;
      while ((cur + cur + 1) <= k) cur = cur + cur + 1, ++len;
      ans.emplace_back(1);
      for (int i = 1; i < len; ++i) ans.emplace_back(0);
      k -= cur;
    }
    cout << ans.size() << '\n';
    for (int x : ans) printf("%d ", x); puts("");
  }
  return 0;
}