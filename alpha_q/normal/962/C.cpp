#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {
  cin >> n;
  int ans = -1;
  for (ll i = 1; i * i <= n; ++i) {
    ll cur = i * i;
    string one = to_string(n), two = to_string(cur);
    int k = 0;
    for (int j = 0; j < one.size() and k < two.size(); ++j) {
      if (one[j] == two[k]) ++k;
    }
    if (k == two.size()) {
      int tot = one.size() - two.size();
      // cout << tot << " " << one << " " << two << '\n';
      if (ans == -1 or tot < ans) ans = tot;
    }
  }
  cout << ans << '\n';
  return 0;
}