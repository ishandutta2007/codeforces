#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
  vector<int> ans;
  for (int k = 1; k*k <= n; k++) {
    if (n % k == 0) {
      ans.push_back(k);
      ans.push_back(n/k);
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, w;
    cin >> l >> w;
    vector<int> ans = {1, 2};
    for (int x: {__gcd(l-1, w-1), __gcd(l-2, w), __gcd(l, w-2)}) {
      for (int d: divisors(x)) {
        ans.push_back(d);
      }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    cout << ans.size() << ' ';
    for (int d: ans) {
      cout << d << ' ';
    }
    cout << '\n';
  }
}