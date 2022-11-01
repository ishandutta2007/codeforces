#include <bits/stdc++.h>

using namespace std;

vector <int> ans;
int n, a[6969], tot, cur;

int main() {
  cin >> n >> a[1];
  tot = cur = a[1];
  ans.emplace_back(1);
  for (int i = 2; i <= n; ++i) {
    cin >> a[i]; tot += a[i];
    if (a[1] >= a[i] + a[i]) {
      cur += a[i];
      ans.emplace_back(i);
    }
  }
  if (cur + cur > tot) {
    cout << ans.size() << '\n';
    for (int it : ans) cout << it << " "; cout << '\n';
  } else cout << "0\n";
  return 0;
}