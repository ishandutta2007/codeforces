#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void test() {
  int n, q;
  cin >> n >> q;
  vector<int> candies(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> candies[i];
  }
  sort(candies.begin() + 1, candies.end(), greater<int>());
  for (int i = 1; i <= n; ++i) {
    candies[i] += candies[i - 1];
  }

  // candies[i] = with i candies how much I can get.
  while (q--) {
    int val;
    cin >> val;
    if (val > candies[n]) {
      cout << "-1\n";
      continue;
    }
    cout << lower_bound(candies.begin(), candies.end(), val) - candies.begin()
         << '\n';
  }
}

int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    test();
  }
  return 0;
}